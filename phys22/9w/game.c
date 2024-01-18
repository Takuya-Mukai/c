#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 8

void getword(const char *filename, char *result) {
  FILE *file;
  int targetRow;

  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random number between 0 and 499
  targetRow = rand() % 500;

  // Open the CSV file
  file = fopen(filename, "r");

  if (file == NULL) {
    perror("Unable to open the file");
    return;
  }

  // Skip to the targetRow-th line
  for (int i = 1; i < targetRow; i++) {
    if (fscanf(file, "%*[^\n]\n") == EOF) {
      perror("Unable to open the file");
      fclose(file);
      return;
    }
  }

  // Get the word from the targetRow-th line
  if (fscanf(file, "%*d,%7s", result) != 1) {
    printf("Data not found.\n");
  }

  // Close the file
  fclose(file);
}

int main() {
  char word[MAX_WORD_LENGTH];
  char input[MAX_WORD_LENGTH];
  int flag = 0;
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                       'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  // initialize index by 'O'
  char index[26];
  for (int i = 0; i < 26; i++) {
    index[i] = 'o';
  }
  // Get a random word from the CSV file
  getword("7_letter_words.csv", word);

  // Display the retrieved word or perform other operations
  // printf("Random Word: %s\n", word);

  for (int try = 0; try < 8; try++) {
    printf("\n");
    printf("input 7 letter word.\n");
    if (scanf("%7s", input) != 1) {
      printf("Failed to read the input.\n");
      return 0;
    }

    if (strcmp(word, input) == 0) {
      flag = 0;
    } else {
      flag = 1;
    }

    if (flag == 0) {
      printf("result: right\n");
      return 0;
    }

    int input1[sizeof(input)];

    if (flag != 0) {
      printf("Result: wrong\n");
      /* evaluate the input
       * if the letter of input is same, it will be -1
       * if the letter of input is different, but if included in other position,
       * it will be 0, and counted how many word it has.
       * remaining will be done nothing.
       */

      // if letter is correct, it will be -1
      // if the letter is incorrect, it wil be 0.
      for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (input[i] == word[i]) {
          input1[i] = -1;
        } else {
          input1[i] = 0;
        }
      }
      // if there is same letter inthe words, it will be counted.
      for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (input1[i] == 0) {
          for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            if (input[i] == word[j]) {
              input1[i]++;
            }
          }
        }
      }

      printf("input: %s\n", input);
      printf("       ");
      for (int i = 0; i < MAX_WORD_LENGTH - 1; i++) {
        if (input1[i] == -1) {
          printf("O");
          for (int j = 0; j < 26; j++) {
            if (input[i] == alphabet[j]) {
              index[j] = 'O';
              break;
            }
          }
        } else if (input1[i] == 0) {
          for (int j = 0; j < 26; j++) {
            if (input[i] == alphabet[j]) {
              index[j] = 'X';
              break;
            }
          }
          printf("%d", input1[i]);
        } else {
          for (int j = 0; j < 26; j++) {
            if (input[i] == alphabet[j]) {
              index[j] = 'O';
              break;
            }
          }
          printf("%d", input1[i]);
        }
      }
      printf("\n");
      // initialize flag
      flag = 0;
      // initialize input1 by -2
      for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        input1[i] = -2;
      }
    }
    printf("%s\n", alphabet);
    printf("%s\n", index);
    printf("You have %d chances left\n", 6 - try);
  }
  printf("the answer is %s\n", word);
  return 0;
}
