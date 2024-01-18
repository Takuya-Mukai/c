#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 8

void getword(const char *filename, char *result) {
  FILE *file;
  int targetRow;

  srand(time(NULL));
  targetRow = rand() % 500;

  file = fopen(filename, "r");

  if (file == NULL) {
    perror("Unable to open the file");
    return;
  }

  for (int i = 1; i < targetRow; i++) {
    if (fscanf(file, "%*[^\n]\n") == EOF) {
      perror("Unable to open the file");
      fclose(file);
      return;
    }
  }

  if (fscanf(file, "%*d,%7s", result) != 1) {
    printf("Data not found.\n");
  }

  fclose(file);
}

int main() {
  char word[MAX_WORD_LENGTH];
  char input[MAX_WORD_LENGTH];
  int flag = 0;
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                       'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char index[26];
  for (int i = 0; i < 26; i++) {
    index[i] = 'O';
  }

  getword("7_letter_words.csv", word);

  for (int try = 0; try < 11; try++) {
    printf("input 7 letter word.\n");
    if (scanf("%7s", input) != 1) {
      printf("Failed to read the input.\n");
    }

    if (strcmp(word, input) == 0) {
      flag = 0;
    } else {
      flag = 1;
    }

    if (flag == 0) {
      printf("You're right!\n");
      return 0;
    }

    int input1[sizeof(input)];

    if (flag != 0) {
      printf("You're wrong!\n");

      for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (input[i] == word[i]) {
          input1[i] = -1;
        } else {
          input1[i] = 0;
        }
      }

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
      printf("input: ");
      for (int i = 0; i < MAX_WORD_LENGTH - 1; i++) {
        if (input1[i] == -1) {
          printf("O");
        } else if (input1[i] == 0) {
          for (int j; j < 26; j++) {
            if (input[i] == alphabet[j]) {
              index[j] = 'X';
              break;
            }
          }
          printf("%c", input1[i] + '0');
        } else {
          printf("%c", input1[i] + '0');
        }
      }
      printf("\n");

      flag = 0;
      for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        input1[i] = -2;
      }
    }
    printf("You have %d chances left\n", 9 - try);
    printf("%s\n", alphabet);
    printf("%s\n", index);
  }
  printf("the answer is %s\n", word);
  return 0;
}
