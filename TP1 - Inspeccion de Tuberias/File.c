//
//  File.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <string.h>

#include "File.h"

#define FILE_OPEN_MODE_READ "rb"
#define FILE_OPEN_MODE_WRITE "w"

char *getOpenMode(FileOpenMode open_mode) {
    if (open_mode == FileOpenModeRead) {
        return FILE_OPEN_MODE_READ;
    } else if (open_mode == FileOpenModeWrite) {
        return FILE_OPEN_MODE_WRITE;
    }

    return "";
}

void fileCreate(File *file, const char *fileName, FileOpenMode openMode) {
    file->file = NULL;
    file->endOfFile = 0;
    file->openCode = FileOpenCodeFail;

    if (fileName != NULL && strlen(fileName) > 0) {
        file->file = fopen(fileName, getOpenMode(openMode));
    }

    if (file->file != NULL) {
        file->openCode = FileOpenCodeSuccess;
    }
}

void fileDestroy(File *file) {
    file->endOfFile = EOF;
    file->openCode = FileOpenCodeFail;

    if (file->file != NULL) {
        fclose(file->file);
    }
}

FileOpenCode fileOpenCode(File *file) {
	return file->openCode;
}

void fileReadLine(File *file, char *line, int maxLenght) {
    if (fgets(line, maxLenght, file->file) == NULL) {
        file->endOfFile = EOF;
    }
}

void fileRead(File *file, char *line, int bytesToRead) {
	if (fread(line, bytesToRead, 1, file->file) == 0) {
		file->endOfFile = EOF;
	}
}
