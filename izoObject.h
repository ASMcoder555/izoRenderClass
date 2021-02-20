#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
using namespace std;
using namespace sf;

struct izoObject {
	int32_t ID; // ���������� ������������� �������.
	int32_t number; // ���������� ��������� ����� ����
	double coordinate_x, coordinate_y; // �������� ����� [0..1], ��� �������� �������� ������ ������ 
	bool on_floor;  // �������� ������� �� �� ��� �����, ���� true, �� ��� ���� �� ����� �������������� �������� � ������ ��������������.
	bool combination = false; // ���� true, �� ������� ������ ���� ������������, ������� ����� ����������, � ���� ����������.
	Sprite objectSprite;
	Transform objectTransform;
}; // ������ �������� ���� ��������� �� ����������.


#define OBJECT_DOES_NOT_EXIST -1
#define NOT_ENOUGH_OBJECTS -2

class izoObjectList {
	vector<izoObject> objects;
	int32_t objectCounts;

public:
	izoObjectList();
	izoObjectList(vector<izoObject> objects);
	izoObject getObject(int32_t number);
	int32_t getObjectCounts();
	void addObject(int32_t ID, int32_t number, double coord_x, double coord_y, bool on_floor, bool combination);
	void addObject(izoObject object, int32_t number);
	void addObject(izoObject object);
	void removeObject(int32_t ID, int32_t number = 1);
	int32_t findObject(int32_t ID);
	int32_t findObjectCount(int32_t ID);
	int32_t findObjectsNumbers(int32_t ID);
	int32_t findObject(int32_t ID, int32_t objectNumber);
private:
};
