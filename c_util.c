//
// Created by dev on 2021/5/7.
//
#include "c_util.h"

//String split_string thread-safe
char** split(char *source, const char* delimiter, int *array_len) {
  char **outStr = NULL, *token = NULL;
  int arrayLen = 0;
  char* pSave = NULL;
  source = strdup(source);
  if(source == NULL || delimiter == NULL)
    return NULL;
  token = strtok_r(source, delimiter, &pSave);
  while (token != NULL) {
    outStr = realloc(outStr, (arrayLen + 1) * sizeof(char*));
    if(outStr == NULL)
      return NULL;
    size_t token_length = strlen(token) + 1;
    *(outStr + arrayLen) = malloc(token_length * sizeof(char));
    strncpy(*(outStr+arrayLen), token, token_length);
    arrayLen++;
    token = strtok_r(NULL, delimiter, &pSave);
  }
  *array_len = arrayLen;
  free(source);
  return outStr;
}

// caller must free returned ptr
char* getFormatTime() {
  time_t rawtime;
  struct tm * timeinfo = NULL;
  int def_buf_size = 128;
  char *buffer = malloc(sizeof(char) * def_buf_size);
  if (!buffer) {
    PRINT_INFO("malloc failed %s:%d \n", __FILE__, __LINE__);
    return NULL;
  }

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  if (timeinfo) {
    strftime(buffer,sizeof(char)*def_buf_size,"%Y-%m-%d %H:%M:%S",timeinfo);
    //printf("%s\n", buffer);
    return buffer;
  }else {
    free(buffer);
    return NULL;
  }
}

//Starts With
bool startswith(char *source, char* find) {
  if(source == NULL || find == NULL)
    return false;
  if((strstr(source, find) - source) == 0) {
    return true;
  }
  return false;
}

bool contains(const char *source, char *find) {
  char *exist=NULL;
  if(source == NULL || find == NULL)
    return false;
  exist = strstr(source, find);
  return exist != NULL;
}

int myusleep(useconds_t useconds) {
  struct timespec ts = { .tv_sec = (long int) (useconds / 1000000),
      .tv_nsec = (long int) (useconds % 1000000) * 1000ul };
  /* Note the usleep() is a cancellation point.  But since we call
     nanosleep() which itself is a cancellation point we do not have
     to do anything here.  */
  return nanosleep(&ts, NULL);
}

void mysystem(const char *cmd)
{
    char result[10240] = {0};
    char buf[1024] = {0};
    FILE *fp = NULL;

    if( (fp = popen(cmd, "r")) == NULL ) {
        printf("popen error!\n");
        return;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        strcat(result, buf);
    }

    pclose(fp);
    printf("result: %s\n", result);
}

