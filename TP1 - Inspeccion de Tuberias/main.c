//
//  main.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>

#include "Parameters.h"
#include "File.h"

static int const kExecutionNormal = 0;
static int const kExecutionError = 1;

static char *const kParametersError = "La cantidad de parámetros es inválida\n";
static char *const kFilesOpenError = "Archivo inválido\n";

FileOpenCode createFiles(Parameters *parameters,
						File *measuresFile,
						File *pipesFile,
						File *routesFile) {
	fileCreate(measuresFile,
				parameterMeasuresFileName(parameters),
				FileOpenModeReadBinary);

	fileCreate(pipesFile,
				parameterPipesFileName(parameters),
				FileOpenModeReadText);

	fileCreate(routesFile,
				parameterRoutesFileName(parameters),
				FileOpenModeReadText);

	if (fileOpenCode(measuresFile) == FileOpenCodeFail ||
		fileOpenCode(pipesFile) == FileOpenCodeFail ||
		fileOpenCode(routesFile) == FileOpenCodeFail) {
		return FileOpenCodeFail;
	}

	return FileOpenCodeSuccess;
}

int main(int argc, const char *argv[]) {
	Parameters parameters;
	File measuresFile;
	File pipesFile;
	File routesFile;

	parametersCreate(&parameters, argc, argv);
	if (parametersCode(&parameters) == ParametersCodeFail) {
		printf("%s", kParametersError);
		parametersDestroy(&parameters);
		return kExecutionError;
	}

	FileOpenCode openCode = createFiles(&parameters,
										&measuresFile,
										&pipesFile,
										&routesFile);
	if (openCode == FileOpenCodeFail) {
		parametersDestroy(&parameters);
		fileDestroy(&measuresFile);
		fileDestroy(&pipesFile);
		fileDestroy(&routesFile);
		printf("%s", kFilesOpenError);
		return kExecutionError;
	}

	fileDestroy(&measuresFile);
	fileDestroy(&pipesFile);
	fileDestroy(&routesFile);
	parametersDestroy(&parameters);
	return kExecutionNormal;
}
