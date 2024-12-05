q6:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;

typedef struct {
    char type[50];
    char growthStage[50];
    float expectedYield;
    Weather *forecast;
} Crop;

typedef struct {
    char type[50];
    int operationalStatus;
    float fuelLevel;
    char schedule[100];
} Equipment;

typedef struct {
    float soilNutrients;
    float pHLevel;
    float pestActivity;
} Sensor;

typedef struct {
    float gpsLatitude;
    float gpsLongitude;
    float soilHealth;
    float moistureLevel;
    Crop *crops;
    int cropCount;
    Equipment *equipment;
    int equipmentCount;
    Sensor *sensors;
    int sensorCount;
} Field;

typedef struct {
    Field *fields;
    int fieldCount;
    float aggregatedYieldPrediction;
    char resourceDistribution[100];
    char emergencyResponsePlan[100];
} RegionalHub;

void initializeWeather(Weather *weather, float temperature, float rainfall, float windSpeed) {
    weather->temperature = temperature;
    weather->rainfall = rainfall;
    weather->windSpeed = windSpeed;
}

void initializeCrop(Crop *crop, const char *type, const char *growthStage, float expectedYield, Weather *forecast) {
    strcpy(crop->type, type);
    strcpy(crop->growthStage, growthStage);
    crop->expectedYield = expectedYield;
    crop->forecast = forecast;
}

void initializeEquipment(Equipment *equipment, const char *type, int operationalStatus, float fuelLevel, const char *schedule) {
    strcpy(equipment->type, type);
    equipment->operationalStatus = operationalStatus;
    equipment->fuelLevel = fuelLevel;
    strcpy(equipment->schedule, schedule);
}

void initializeSensor(Sensor *sensor, float soilNutrients, float pHLevel, float pestActivity) {
    sensor->soilNutrients = soilNutrients;
    sensor->pHLevel = pHLevel;
    sensor->pestActivity = pestActivity;
}

void initializeField(Field *field, float latitude, float longitude, float soilHealth, float moistureLevel, int cropCount, int equipmentCount, int sensorCount) {
    field->gpsLatitude = latitude;
    field->gpsLongitude = longitude;
    field->soilHealth = soilHealth;
    field->moistureLevel = moistureLevel;
    field->cropCount = cropCount;
    field->equipmentCount = equipmentCount;
    field->sensorCount = sensorCount;
    field->crops = (Crop *)malloc(cropCount * sizeof(Crop));
    field->equipment = (Equipment *)malloc(equipmentCount * sizeof(Equipment));
    field->sensors = (Sensor *)malloc(sensorCount * sizeof(Sensor));
}

void initializeRegionalHub(RegionalHub *hub, int fieldCount) {
    hub->fieldCount = fieldCount;
    hub->fields = (Field *)malloc(fieldCount * sizeof(Field));
    hub->aggregatedYieldPrediction = 0.0;
    strcpy(hub->resourceDistribution, "Default");
    strcpy(hub->emergencyResponsePlan, "Default");
}

void freeField(Field *field) {
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

void freeRegionalHub(RegionalHub *hub) {
    for (int i = 0; i < hub->fieldCount; i++) {
        freeField(&hub->fields[i]);
    }
    free(hub->fields);
}

int main() {
    int hubCount = 1;
    RegionalHub *regionalHubs = (RegionalHub *)malloc(hubCount * sizeof(RegionalHub));
    initializeRegionalHub(&regionalHubs[0], 2);

    initializeField(&regionalHubs[0].fields[0], 45.123, -93.456, 85.0, 40.0, 2, 2, 2);
    Weather w1 = {22.5, 12.3, 5.0};
    initializeCrop(&regionalHubs[0].fields[0].crops[0], "Corn", "Vegetative", 1500.0, &w1);
    initializeEquipment(&regionalHubs[0].fields[0].equipment[0], "Tractor", 1, 75.0, "Daily");

    freeRegionalHub(&regionalHubs[0]);
    free(regionalHubs);
    return 0;
}
