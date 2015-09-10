//
//  Parameters.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

typedef enum {
    ParametersCodeOK,
    ParametersCodeFail
} ParametersCode;

typedef struct {
    const char *measure_file_name;
    const char *pipe_file_name;
    const char *route_file_name;
} Parameters;

void parametersCreate(Parameters *parameters_parser,
					  int parameters_count,
					  const char *parameters[]);

void parametersDestroy(Parameters *parameters_parser);

#endif /* PARAMETERS_H_ */
