//
//  File.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "File.h"

void fileCreate(File *file, char *file_name, FileOpenMode open_mode) {
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
