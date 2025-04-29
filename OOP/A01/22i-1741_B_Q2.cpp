#include <iostream>
#include <cstring>

using namespace std;

// Function prototypes
char* toupper(char* ch);
char* tolower(char* ch);
int isspace(const char* ch);
char* strncpy(char* dest, const char* src, size_t n);
int strcmp(const char* cstr1, const char* cstr2);
char* strncat(char* dest, const char* src, size_t n);
char* strstr(char* cstr1, char* cstr2);
char* strtok(char* cstr, const char* delim);

int main() {
  // Get input from user
  char* input = new char[100];
  
  cout << "Enter a string: ";
  cin.getline(input, 100);

  // Call functions on input
  char* upper = toupper(input);
  cout << "Uppercase string: " << upper << endl;

  char* lower = tolower(input);
  cout << "Lowercase string: " << lower << endl;

  int spaces = isspace(input);
  cout << "Spaces in string: " << spaces << endl;

  char* dest = new char[100];
  strncpy(dest, input, 5);
  cout << "Copied string: " << dest << endl;

  char* compare = new char[100];
  cout << "Enter a string to compare: ";
  cin.getline(compare, 100);
  int result = strcmp(input, compare);
  cout << "Comparison result: " << result << endl;

  char* concat = new char[100];
  strncat(concat, input, 3);
  cout << "Concatenated string: " << concat << endl;

  /*char* find = new char[100];
  cout << "Enter a string to find: ";
  cin.getline(find, 100);
  char* substring = strstr(input, find);
  if (substring != NULL) {
    cout << "Substring found at position " << substring - input << endl;
  } else {
    cout << "Substring not found" << endl;
  }*/

  /*char* token = strtok(input, " ");
  while (token != NULL) {
    cout << "Token: " << token << endl;
    token = strtok(NULL, " ");
  }*/


  char* cstr1 = new char[100];
    char* cstr2 = new char[100];
    char* cstr3 = new char[100];

    cout << "Enter first string: ";
    cin.getline(cstr1, 100);

    cout << "Enter second string: ";
    cin.getline(cstr2, 100);

    cout << "Enter third string: ";
    cin.getline(cstr3, 100);

  char* result_strstr = strstr(cstr1, cstr2);
    if (result_strstr != nullptr) {
        cout << "The second string is found in the first string at index " << result_strstr - cstr1 << endl;
    } else {
        cout << "The second string is not found in the first string." << endl;
    }

    // Call strtok function
    cout << "The tokens in the third string are: ";
    char* token = strtok(cstr3, " ");
    while (token != nullptr) {
        cout << token << " ";
        token = strtok(nullptr, " ");
    }
    cout << endl;

    // Free allocated memory
    delete[] cstr1;
    delete[] cstr2;
    delete[] cstr3;



  // Free dynamically allocated memory
  delete[] input;
  delete[] upper;
  delete[] lower;
  delete[] dest;
  delete[] compare;
  delete[] concat;
  //delete[] find;

  return 0;
}

// Function definitions

char* toupper(char* ch) {
  int length = strlen(ch);
  char* upper = new char[length + 1];
  for (int i = 0; i < length; i++) {
    upper[i] = toupper(ch[i]);
  }
  upper[length] = '\0';
  return upper;
}

char* tolower(char* ch) {
  int length = strlen(ch);
  char* lower = new char[length + 1];
  for (int i = 0; i < length; i++) {
    lower[i] = tolower(ch[i]);
  }
  lower[length] = '\0';
  return lower;
}

int isspace(const char* ch) {
  int spaces = 0;
  int length = strlen(ch);
  for (int i = 0; i < length; i++) {
    if (isspace(ch[i])) {
      spaces++;
    }
  }
  return spaces;
}

// function to copy n characters from src into dest
char* my_strncpy(char* dest, const char* src, size_t n) {
    char* ptr = dest;
    while (n && (*ptr++ = *src++)) {
        --n;
    }
    if (n) {
        while (--n) {
            *ptr++ = '\0';
        }
    }
    return dest;
}

// function to compare two strings
int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

// function to append n characters from src into dest
char* my_strncat(char* dest, const char* src, size_t n) {
    char* ptr = dest;
    while (*ptr) {
        ++ptr;
    }
    while (n && (*ptr++ = *src++)) {
        --n;
    }
    *ptr = '\0';
    return dest;
}

char* strstr(char* cstr1, char* cstr2) {
    char* p = cstr1;
    while (*p != '\0') {
        char* p1 = p;
        char* p2 = cstr2;
        while (*p1 == *p2 && *p2 != '\0') {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            return p;
        }
        p++;
    }
    return nullptr;
}

char* strtok(char* cstr, const char* delim) {
    static char* p = nullptr;
    if (cstr != nullptr) {
        p = cstr;
    }
    if (p == nullptr) {
        return nullptr;
    }
    char* start = p;
    while (*p != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*p == *d) {
                *p = '\0';
                p++;
                if (start == p) {
                    start = p;
                    continue;
                }
                return start;
            }
            d++;
        }
        p++;
    }
    return start == p ? nullptr : start;
}
