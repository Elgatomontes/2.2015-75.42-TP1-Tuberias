//
//  main.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>

#include "PipesProcessor.h"
#include "Parameters.h"
#include "Arguments.h"
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

	if (fileOpenCode(measuresFile) == FileOpenCodeFail) {
		return FileOpenCodeFail;
	}

	fileCreate(pipesFile,
			parameterPipesFileName(parameters),
			FileOpenModeReadText);

	if (fileOpenCode(pipesFile) == FileOpenCodeFail) {
		fileDestroy(measuresFile);
		return FileOpenCodeFail;
	}

	fileCreate(routesFile,
			parameterRoutesFileName(parameters),
			FileOpenModeReadText);

	if (fileOpenCode(routesFile) == FileOpenCodeFail) {
		fileDestroy(measuresFile);
		fileDestroy(pipesFile);
		return FileOpenCodeFail;
	}

	return FileOpenCodeSuccess;
}

int main(int argc, const char *argv[]) {
	Parameters parameters;
	File measuresFile;
	File pipesFile;
	File routesFile;
	PipesProcessor processor;

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
		printf("%s", kFilesOpenError);
		return kExecutionError;
	}

	pipesProcessorCreate(&processor);

	fileDestroy(&measuresFile);
	fileDestroy(&pipesFile);
	fileDestroy(&routesFile);
	parametersDestroy(&parameters);
	pipesProcessorDestroy(&processor);
	return kExecutionNormal;
}
