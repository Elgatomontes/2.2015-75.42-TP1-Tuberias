//
//  Parameters.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "Parameters.h"

#define MEASURE_FILE_INDEX 1
#define PIPES_FILE_INDEX 2
#define ROUTES_FILE_INDEX 3

void setInvalidConfiguration(Parameters *parameters) {
    parameters->parameters_code = ParametersCodeFail;
    parameters->measures_file_name = NULL;
    parameters->pipes_file_name = NULL;
    parameters->routes_file_name = NULL;
}

void parseParameters(Parameters *parameters_parser, const char *parameters[]) {
	parameters_parser->measures_file_name = parameters[MEASURE_FILE_INDEX];
	parameters_parser->pipes_file_name = parameters[PIPES_FILE_INDEX];
	parameters_parser->routes_file_name = parameters[ROUTES_FILE_INDEX];
}

void parametersCreate(Parameters *parameters_parser,
					  int parameters_count,
					  const char *parameters[]) {
	setInvalidConfiguration(parameters_parser);

	switch (parameters_count) {
		case 4:
			parseParameters(parameters_parser, parameters);
			parameters_parser->parameters_code = ParametersCodeOK;
			break;
		default:
			setInvalidConfiguration(parameters_parser);
			break;
	}
}

void parametersDestroy(Parameters *parameters_parser) {
	setInvalidConfiguration(parameters_parser);
}

ParametersCode parametersCode(Parameters *parameters_parser) {
	return parameters_parser->parameters_code;
}

const char *parameterMeasuresFileName(Parameters *parameters_parser) {
	return parameters_parser->measures_file_name;
}

const char *parameterPipesFileName(Parameters *parameters_parser) {
	return parameters_parser->pipes_file_name;
}

const char *parameterRoutesFileName(Parameters *parameters_parser) {
	return parameters_parser->routes_file_name;
}
