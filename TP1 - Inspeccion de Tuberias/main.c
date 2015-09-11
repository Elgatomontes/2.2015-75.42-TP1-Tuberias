//
//  main.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>

#include "Parameters.h"

#define EXECUTION_NORMAL 0
#define EXECUTION_ERROR 1

int main(int argc, const char *argv[]) {
	Parameters parameters;

	parametersCreate(&parameters, argc, argv);
	if (parametersCode(&parameters) == ParametersCodeFail) {
		printf("Error en la creación de los parámetros.\n");
		return EXECUTION_ERROR;
	}

	printf("Primer parámetro: %s\n", parameters.measures_file_name);
	printf("Segundo parámetro: %s\n", parameters.pipes_file_name);
	printf("Tercer parámetro: %s\n", parameters.routes_file_name);

	return EXECUTION_NORMAL;
}
