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

int main(int argc, const char *argv[]) {
	Parameters parameters;
	File measuresFile;
	File pipesFile;
	File routesFiles;

	parametersCreate(&parameters, argc, argv);
	if (parametersCode(&parameters) == ParametersCodeFail) {
		printf("Error en la creación de los parámetros.\n");
		parametersDestroy(&parameters);
		return EXECUTION_ERROR;
	}

	// @TODO: Gastón - Pasar esto a un único método y que sea el método el que dice si fue Ok o fail.
	fileCreate(&measuresFile,
			parameterMeasuresFileName(&parameters),
			FileOpenModeRead);

	fileCreate(&pipesFile,
			parameterPipesFileName(&parameters),
			FileOpenModeRead);

	fileCreate(&routesFiles,
			parameterRoutesFileName(&parameters),
			FileOpenModeRead);

	fileDestroy(&measuresFile);
	fileDestroy(&pipesFile);
	fileDestroy(&routesFiles);
	parametersDestroy(&parameters);
	return EXECUTION_NORMAL;
}
