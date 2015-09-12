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

char *openMode(FileOpenMode open_mode) {
    if (open_mode == FileOpenModeRead) {
        return FILE_OPEN_MODE_READ;
    } else if (open_mode == FileOpenModeWrite) {
        return FILE_OPEN_MODE_WRITE;
    }

    return "";
}

void fileCreate(File *file, const char *file_name, FileOpenMode open_mode) {
    file->file = NULL;
    file->end_of_file = 0;
    file->operation_code = FileOperationCodeFail;

    if (file_name != NULL && strlen(file_name) > 0) {
        file->file = fopen(file_name, openMode(open_mode));
    }

    if (file->file != NULL) {
        file->operation_code = FileOperationCodeSuccess;
    }
}

void fileDestroy(File *file) {
    file->end_of_file = EOF;
    file->operation_code = FileOperationCodeFail;

    if (file->file != NULL) {
        fclose(file->file);
    }
}
