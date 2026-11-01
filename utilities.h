#ifndef UTILITIES_H
#define UTILITIES_H

void  clearBuffer(void);
void  readLine(const char *prompt, char *buf, int size);
float readAmount(const char *prompt);
int   readPositiveInt(const char *prompt);
int   readChoice(void);

#endif