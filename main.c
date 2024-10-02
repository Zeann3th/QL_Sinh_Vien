#include "sinhvien.h"
#include "sort.h"
#include <cstring>
#include <stdio.h>
#include <unistd.h>

SinhVien *arr[1000];
char tmp[30];
int count;

void intro() {
  printf("Qly Sinh Vien\n");
  printf("--------------------------------\n");
  printf("1. Them sinh vien\n");
  printf("2.Sap xep danh sach\n");
  printf("3. In danh sach\n");
  printf("4.Thoat chuong trinh\n");
}

void printList() {
  for (int i = 0; i < count; i++) {
    printf("%s\n", arr[i]->fullName);
  }
  sleep(5);
}

void add() {
  SinhVien *sv = new SinhVien();
  printf("Hay nhap ten sinh vien:");
  getchar(); // Just consume the '\n' from the previous input
  scanf("%[^\n]", sv->fullName);

  // Copy full name
  strcpy(tmp, sv->fullName);

  // Fetch the first name from full name
  char *token = strtok(tmp, " ");
  while (token != NULL) {
    sv->firstName = token;
    token = strtok(NULL, " ");
  }

  // The rest save to last name
  int fullLen = strlen(sv->fullName);
  int firstLen = strlen(sv->firstName);
  strncpy(tmp, sv->fullName, fullLen - firstLen - 1);
  sv->lastName = tmp;

  printf("%s - %s\n", sv->lastName, sv->firstName);
  sleep(1);
  arr[count] = sv;
  count++;
}

int main() {
  bool isRunning = true;
  int choice;
  while (isRunning) {
    system("cls");
    intro();
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      add();
      break;
    case 2:
      quicksort(arr, 0, count - 1);
      printList();
      break;
    case 3:
      printList();
      break;
    case 4:
      isRunning = false;
      break;
    default:
      isRunning = false;
      break;
    }
  }
}
