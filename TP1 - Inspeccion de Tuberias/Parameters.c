//
//  Parameters.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "Parameters.h"

void setInvalidConfiguration(Parameters *parameters)
{
    parameters->parameters_code = ParametersCodeFail;
    parameters->measures_file_name = NULL;
    parameters->pipes_file_name = NULL;
    parameters->routes_file_name = NULL;
}

void parametersCreate(Parameters *parameters_parser,
					  int parameters_count,
					  const char *parameters[]) {
	setInvalidConfiguration(parameters_parser);

}

void parametersDestroy(Parameters *parameters_parser) {

}

ParametersCode parametersCode(Parameters *parameters_parser) {
	return ParametersCodeFail;
}

const char *parameterMeasuresFileName(Parameters *parameters_parser) {
	return NULL;
}

const char *parameterPipesFileName(Parameters *parameters_parser) {
	return NULL;
}

const char *parameterRoutesFileName(Parameters *parameters_parser) {
	return NULL;
}
