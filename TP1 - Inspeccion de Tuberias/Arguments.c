//
//  Arguments.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 19/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <math.h>

#include "Arguments.h"

static int const kArgumentSize = 4;
static float const kThresholdDistance = 0.5;
static int const kMinutesInAnHour = 60;

int argumentsCalculateThreshold(Arguments *arguments) {
	int sensingSpeed = arguments->sensingSpeed;
	int flowSpeed = arguments->flowSpeed;
	float distancePerHour = kThresholdDistance * kMinutesInAnHour;
	float threshold = distancePerHour * sensingSpeed / flowSpeed;
	return ceilf(threshold);
}

void argumentsCreate(Arguments *arguments, File *file) {
	arguments->flowSpeed = 0;
	arguments->sensingSpeed = 0;
	arguments->sensorsNumber = 0;
	arguments->thresholdSamples = 0;

	char *argumentsBuffer = (char *)malloc(kArgumentSize);

	fileRead(file, argumentsBuffer, kArgumentSize);
	arguments->flowSpeed = atoi(argumentsBuffer);

	fileRead(file, argumentsBuffer, kArgumentSize);
	arguments->sensingSpeed = atoi(argumentsBuffer);

	fileRead(file, argumentsBuffer, kArgumentSize);
	arguments->sensorsNumber = atoi(argumentsBuffer);

	arguments->thresholdSamples = argumentsCalculateThreshold(arguments);

	free(argumentsBuffer);
}

void argumentsDestroy(Arguments *arguments) {
	arguments->flowSpeed = 0;
	arguments->sensingSpeed = 0;
	arguments->sensorsNumber = 0;
	arguments->thresholdSamples = 0;
}

int argumentsFlowSpeed(Arguments *arguments) {
	return arguments->flowSpeed;
}

int argumentsSensingSpeed(Arguments *arguments) {
	return arguments->sensingSpeed;
}

int argumentsSensorsNumber(Arguments *arguments) {
	return arguments->sensorsNumber;
}

int argumentsThresholdSamples(Arguments *arguments) {
	return arguments->thresholdSamples;
}
