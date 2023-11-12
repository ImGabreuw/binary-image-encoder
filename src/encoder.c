#include "../include/parser.h"
#include "../include/encoder.h"

void encode(Image img, int startRow, int endRow, int startCol, int endCol, char *code)
{
  if (startRow > endRow || startCol > endCol)
  {
    return; // Caso base: subimagem inválida
  }

  // Verificar se a imagem é uniforme (regra 1)
  int isUniform = 1;
  int firstPixel = img.pixels[startRow * img.width + startCol];

  for (int i = startRow; i <= endRow; ++i)
  {
    for (int j = startCol; j <= endCol; ++j)
    {
      if (img.pixels[i * img.width + j] != firstPixel)
      {
        isUniform = 0;
        break;
      }
    }
    if (!isUniform)
    {
      break;
    }
  }

  // Se for uniforme, adicionar o código correspondente (regra 1)
  if (isUniform)
  {
    sprintf(code, "%s%c", code, (firstPixel == 0) ? 'B' : 'P');
  }
  else
  {
    // Se não for uniforme, adicionar 'X' e dividir a imagem em 4 quadrantes (regra 2)
    sprintf(code, "%sX", code);

    int midRow = (startRow + endRow) / 2;
    int midCol = (startCol + endCol) / 2;

    // Chamar a função recursivamente para cada quadrante
    encode(img, startRow, midRow, startCol, midCol, code);     // 1º quadrante
    encode(img, startRow, midRow, midCol + 1, endCol, code);   // 2º quadrante
    encode(img, midRow + 1, endRow, startCol, midCol, code);   // 3º quadrante
    encode(img, midRow + 1, endRow, midCol + 1, endCol, code); // 4º quadrante
  }
}