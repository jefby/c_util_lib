// caller must free returned ptr
static char* getFormatTime() {
    time_t rawtime;
    struct tm * timeinfo;
    int def_buf_size = 128;
    char *buffer = malloc(sizeof(char) * def_buf_size);

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(char)*def_buf_size,"%Y-%m-%d %H:%M:%S",timeinfo);
    //printf("%s\n", buffer);
    return buffer;
}


//String split_string
static char** split(char *source, const char* delimiter, int *array_len) {
    char **outStr = NULL, *token = NULL;
    int arrayLen = 0;
    source = strdup(source);
    if(source == NULL || delimiter == NULL)
        return NULL;
    token = strtok(source, delimiter);
    while (token != NULL) {
        outStr = realloc(outStr, (arrayLen + 1) * sizeof(char*));
        if(outStr == NULL)
            return NULL;
        *(outStr + arrayLen) = malloc((strlen(token) + 1) * sizeof(char));
        *(outStr + arrayLen) = strdup(token);
        arrayLen++;
        token = strtok(NULL, delimiter);
    }
    *array_len = arrayLen;
    return outStr;
}

//Starts With
static bool startswith(char *source, char* find) {
    if(source == NULL || find == NULL)
        return false;
    if((strstr(source, find) - source) == 0) {
        return true;
    }
    return false;
}
