#include "izoObject.h"

izoObjectList::izoObjectList() {}
izoObjectList::izoObjectList(vector<izoObject> objects) : objects(objects) {}

bool sortFunctionObject(izoObject object1, izoObject object2) {
	return object1.coordinate_y < object2.coordinate_y ? true : false;
}

bool findFunctionObject(izoObject object1, izoObject object2) {
	return object1.ID == object2.ID ? true : false;
}

void izoObjectList::addObject(izoObject object, int32_t number) {
	int32_t objectAddr = findObject(object.ID);
	if (objectAddr != -1) {
		objects[objectAddr].number += number;
	}
	else {
		objects.push_back(object);
		sort(objects.begin(), objects.end(), sortFunctionObject);
		objectCounts++;
	}
}

void izoObjectList::addObject(izoObject object) {
	int32_t objectAddr = findObject(object.ID);
	if (objectAddr != -1 && object.combination == true) {
		objects[objectAddr].number += object.number;
	}
	else {
		objects.push_back(object);
		sort(objects.begin(), objects.end(), sortFunctionObject);
		objectCounts++;
	}
}

void izoObjectList::addObject(int32_t ID, int32_t number, double coord_x, double coord_y, bool on_floor, bool combination) {
	izoObject object;
	object.ID = ID;
	object.coordinate_x = coord_x;
	object.coordinate_y = coord_y;
	object.number = number;
	object.on_floor = true;
	object.combination = combination;
	//
	int32_t objectAddr = findObject(ID);
	if (objectAddr != -1 && combination == true) {
		objects[objectAddr].number += number;
	}
	else {
		objects.push_back(object);
		sort(objects.begin(), objects.end(), sortFunctionObject);
		objectCounts++;
	}
}

int32_t izoObjectList::getObjectCounts() {
	return objectCounts;
}

izoObject izoObjectList::getObject(int32_t number) {
	return objects[number];
}

void izoObjectList::removeObject(int32_t ID, int32_t number) {
	int32_t objectAddr = findObject(ID);
	if (objectAddr) {
		if (objects[objectAddr].number < number && objects[objectAddr].combination == true) {
			throw NOT_ENOUGH_OBJECTS;
		}
		else if (objects[objectAddr].number < number && objects[objectAddr].combination == false) {
			int32_t totalcount = 0;
			int32_t totalobject_count = findObjectCount(ID);
			for (int i = 0; i < totalobject_count; i++)
				totalcount += objects[findObject(ID, i)].number;
			if (totalcount < number) {
				throw NOT_ENOUGH_OBJECTS;
			}
			else {
				while (number > 0) {
					izoObject tempObject = objects[findObject(ID)];
					if (number > tempObject.number) {
						number -= tempObject.number;
						removeObject(ID, tempObject.number);
					}
					else {
						removeObject(ID, number);
						number = 0;
					}
				}
			}
		}
		else {
			objects[objectAddr].number -= number;
			if (objects[objectAddr].number == 0) {
				objects.erase(objects.begin() + objectAddr);
				objectCounts--;
			}
		}
	}
	else {
		throw OBJECT_DOES_NOT_EXIST;
	}
}

int32_t izoObjectList::findObject(int32_t ID) {
	for (int32_t i = 0; i < objectCounts; i++) {
		if (objects[i].ID == ID)
			return i;
	}
	return -1;
}

int32_t izoObjectList::findObject(int32_t ID, int32_t objectNumber) {
	for (int32_t i = 0; i < objectCounts; i++) {
		if (objects[i].ID == ID) {
			if (objectNumber == 0) {
				return i;
			}
			else {
				objectNumber--;
			}
		}
	}
	return -1;
}

int32_t izoObjectList::findObjectCount(int32_t ID) {
	int32_t objectCount = 0;
	for (int32_t i = 0; i < objectCounts; i++) {
		if (objects[i].ID == ID)
			objectCount++;
	}
	return objectCount;
}

int32_t izoObjectList::findObjectsNumbers(int32_t ID) {
	int32_t totalcount = 0;
	int32_t totalobject_count = findObjectCount(ID);
	for (int i = 0; i < totalobject_count; i++)
		totalcount += objects[findObject(ID, i)].number;
	return totalcount;
}