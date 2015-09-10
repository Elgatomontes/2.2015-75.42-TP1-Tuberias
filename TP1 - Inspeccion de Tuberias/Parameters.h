//
//  Parameters.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include <stdio.h>

typedef enum {
    ParametersCodeOK,
    ParametersCodeFail
} ParametersCode;

typedef struct {
	ParametersCode parameters_code;
    const char *measures_file_name;
    const char *pipes_file_name;
    const char *routes_file_name;
} Parameters;

void parametersCreate(Parameters *parameters_parser,
					  int parameters_count,
					  const char *parameters[]);

void parametersDestroy(Parameters *parameters_parser);

ParametersCode parametersCode(Parameters *parameters_parser);

const char *parameterMeasuresFileName(Parameters *parameters_parser);

const char *parameterPipesFileName(Parameters *parameters_parser);

const char *parameterRoutesFileName(Parameters *parameters_parser);

#endif /* PARAMETERS_H_ */
