#pragma once

#include <map>
#include <list>
#include <string>

using namespace std;

class ASTExit;

class LuryObject {
private:
	map<string, LuryObject *> fields;
	LuryObject *klass;

public:
	LuryObject(LuryObject *klass);
	~LuryObject();

	inline LuryObject *getField(string field_name) { return fields[field_name]; }
	inline LuryObject *getClass() { return klass; }
	inline void setClass(LuryObject* k) { klass = k; }
	ASTExit call(string name, list<LuryObject *> atgs);

	virtual bool isTrue() { return false; }
	virtual string to_s() { return "Object"; }
	virtual LuryObject *add(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject *sub(LuryObject *obj) { throw "sub not impliment in object"; }
	virtual LuryObject *mul(LuryObject *obj) { throw "mul not impliment in object"; }
	virtual LuryObject *div(LuryObject *obj) { throw "div not impliment in object"; }
	virtual LuryObject *mod(LuryObject *obj) { throw "mod not impliment in object"; }
	virtual LuryObject *equal(LuryObject *obj) { throw "equal not impliment in object"; }
	virtual LuryObject *notEqual(LuryObject *obj) { throw "notEqual not impliment in object"; }
	virtual LuryObject *less(LuryObject *obj) { throw "less not impliment in object"; }
	virtual LuryObject *lessOrEqual(LuryObject *obj) { throw "lessOrEqual not impliment in object"; }
	virtual LuryObject *greater(LuryObject *obj) { throw "greater not impliment in object"; }
	virtual LuryObject *greaterOrEqual(LuryObject *obj) { throw "greaterOrEqual not impliment in object"; }
	LuryObject *luryOr(LuryObject *obj);
};
