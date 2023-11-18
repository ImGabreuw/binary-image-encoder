#!/bin/bash

expected_results_path="tests/expected_results.txt"

if [ ! -f "$expected_results_path" ]; then
  echo "File not found: $expected_results_path"
  exit 1
fi

expected_results=()
counter=0

while IFS= read -r line || [ -n "$line" ]; do
  expected_results["$counter"]="$line"
  ((counter++))
done <"$expected_results_path"

clear && gcc -o main $(find . -name "*.c") -lm

input_files=$(ls ./tests/test_*.txt)
index=0

for input in $input_files; do
  result=$(./main -m <"$input")

  expected_result=${expected_results[$index]}

  if [ "$result" == "$expected_result" ]; then
    echo -e "\e[32mTest passed: $input\e[0m"
    echo "Image code: $result"
  else
    echo -e "\e[31mTest failed: $input\e[0m"
    echo "Expected: $expected_result"
    echo "Got: $result"
  fi

  ((index++))
done
