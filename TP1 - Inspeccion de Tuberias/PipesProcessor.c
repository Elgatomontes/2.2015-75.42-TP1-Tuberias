//
//  PipesProcessor.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <math.h>

#include "PipesProcessor.h"

void createArguments(PipesProcessor *processor, File *measures) {
	Arguments *newArguments = (Arguments *)malloc(sizeof(Arguments));
	argumentsCreate(newArguments, processor->measures);
	processor->arguments = newArguments;
}

int estimateMeasuresCount(PipesProcessor *processor) {
	int routeLenght = pipesRouteLenght(processor->route);
	int sensingSpeed = argumentsSensingSpeed(processor->arguments);
	int flowSpeed = argumentsFlowSpeed(processor->arguments);

	return floor(routeLenght * 60 * sensingSpeed / flowSpeed);
}

void createSensors(PipesProcessor *processor) {
	int estimateMeasures = estimateMeasuresCount(processor);
	int sensorsCount = argumentsSensorsNumber(processor->arguments);

	SensorMeasures *sensors;
	sensors = (SensorMeasures *)malloc(sizeof(SensorMeasures) * sensorsCount);

	for (int i = 0; i < sensorsCount; ++i) {
		sensorMeasuresCreate(&sensors[i], processor->arguments, estimateMeasures);
	}

	processor->sensors = sensors;
}

void pipesProcessorCreate(PipesProcessor *processor,
		File *measuresFile,
		File *pipesFile,
		File *routeFile) {
	processor->measures = measuresFile;

	createArguments(processor, processor->measures);
	pipesRouteCreate(&(processor->route), routeFile, pipesFile);
	createSensors(processor);
}

void pipesProcessorDestroy(PipesProcessor *processor) {
	argumentsDestroy(processor->arguments);
	pipesRouteDestroy(processor->route);

	int sensorsCount = argumentsSensorsNumber(processor->arguments);
	for (int i = 0; i < sensorsCount; ++i) {
		sensorMeasuresDestroy(&processor->sensors[i]);
	}
	free(processor->sensors);

	free(processor->arguments);
}

void pipesProcessorProcess(PipesProcessor *processor) {
	int sensorsCount = argumentsSensorsNumber(processor->arguments);

	while (fileEndOfFile(processor->measures) != EOF) {
		for (int i = 0; i < sensorsCount; ++ i) {
			SensorMeasures sensor = processor->sensors[i];
			sensorMeasuresReadMeasure(&sensor, processor->measures);
		}
	}
}
