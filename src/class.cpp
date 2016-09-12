#include "../include/class.hpp"

map<string, LuryClass *> LuryClass::class_objects;
LuryClass *CLASS_OBJ_OBJECT;
LuryClass *CLASS_OBJ_CLASS;
LuryClass *CLASS_OBJ_FUNCTION;

LuryClass::LuryClass(string name) : LuryObject(CLASS_OBJ_CLASS), name(name) {}

LuryObject *LuryClass::getMethod(string name) {
	LuryObject *method = methods[name];
	if (method == NULL && parent != NULL) {
		method = parent->getMethod(name);
	}
	return method;
}

LuryClass *LuryClass::createClass(string name, LuryClass *parent) {
	LuryClass *new_class = new LuryClass(name);
	new_class->parent = parent;

	class_objects[name] = new_class;
	return new_class;
}

LuryClass *LuryClass::createClass(string name) {
	return createClass(name, CLASS_OBJ_OBJECT);
}

void LuryClass::init() {
	LuryClass *object = new LuryClass("Object");
	LuryClass *klass = new LuryClass("Class");

	object->setClass(klass);
	object->parent = NULL;
	class_objects["Object"] = object;
	CLASS_OBJ_OBJECT = object;

	klass->setClass(klass);
	klass->parent = object;
	class_objects["Class"] = klass;
	CLASS_OBJ_CLASS = klass;
}

LuryClass *LuryClass::getClass(string name) {
	return class_objects[name];
}
