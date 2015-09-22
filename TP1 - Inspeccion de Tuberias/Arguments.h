//
//  Arguments.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 19/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef ARGUMENTS_H_
#define ARGUMENTS_H_

#include <stdio.h>

#include "File.h"

typedef struct {
	int flowSpeed;
	int sensingSpeed;
	int sensorsNumber;
	int thresholdSamples;
} Arguments;

void argumentsCreate(Arguments *arguments, File *file);

void argumentsDestroy(Arguments *arguments);

#endif /* ARGUMENTS_H_ */
