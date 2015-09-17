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

#define EXECUTION_NORMAL 0
#define EXECUTION_ERROR 1

#define PARAMATERS_COUNT_ERROR "La cantidad de parámetros es inválida\n"
#define FILES_OPEN_ERROR "Archivo inválido\n"

FileOpenCode createFiles(Parameters *parameters,
						File *measuresFile,
						File *pipesFile,
						File *routesFile) {
	fileCreate(measuresFile,
				parameterMeasuresFileName(parameters),
				FileOpenModeRead);

	fileCreate(pipesFile,
				parameterPipesFileName(parameters),
				FileOpenModeRead);

	fileCreate(routesFile,
				parameterRoutesFileName(parameters),
				FileOpenModeRead);

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
		printf("%s", PARAMATERS_COUNT_ERROR);
		parametersDestroy(&parameters);
		return EXECUTION_ERROR;
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
		printf("%s", FILES_OPEN_ERROR);
		return EXECUTION_ERROR;
	}

	fileDestroy(&measuresFile);
	fileDestroy(&pipesFile);
	fileDestroy(&routesFile);
	parametersDestroy(&parameters);
	return EXECUTION_NORMAL;
}
