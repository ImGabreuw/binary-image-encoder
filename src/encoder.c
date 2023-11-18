#include "../include/parser.h"
#include "../include/encoder.h"

bool is_uniform(Image image, int start_row, int end_row, int start_col, int end_col)
{
  bool uniform = true;
  int first_pixel = image.pixels[start_row * image.width + start_col];

  for (int i = start_row; i <= end_row; ++i)
  {
    for (int j = start_col; j <= end_col; ++j)
    {
      if (image.pixels[i * image.width + j] != first_pixel)
      {
        uniform = false;
        break;
      }
    }

    if (!uniform)
    {
      break;
    }
  }

  return uniform;
}

void encode(Image image, int start_row, int end_row, int start_col, int end_col, char *code)
{
  if (start_row > end_row || start_col > end_col)
  {
    return; // Caso base: subimagem inválida
  }

  code = realloc(code, strlen(code) + 2);

  // Se for uniforme, adicionar o código correspondente
  if (is_uniform(image, start_row, end_row, start_col, end_col))
  {
    int first_pixel = image.pixels[start_row * image.width + start_col];
    sprintf(code, "%s%c", code, (first_pixel == 0) ? 'B' : 'P');
  }
  else
  {
    // Se não for uniforme, adicionar 'X' e dividir a imagem em 4 quadrantes
    sprintf(code, "%sX", code);

    int mid_row = (start_row + end_row) / 2;
    int mid_col = (start_col + end_col) / 2;

    // Chamar a função recursivamente para cada quadrante
    encode(image, start_row, mid_row, start_col, mid_col, code);     // 1º quadrante
    encode(image, start_row, mid_row, mid_col + 1, end_col, code);   // 2º quadrante
    encode(image, mid_row + 1, end_row, start_col, mid_col, code);   // 3º quadrante
    encode(image, mid_row + 1, end_row, mid_col + 1, end_col, code); // 4º quadrante
  }
}