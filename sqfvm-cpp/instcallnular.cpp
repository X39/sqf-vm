#include "full.h"

void sqf::inst::callnular::execute(const virtualmachine* vm) const
{
	mcmd->execute(vm, value_s(), value_s());
}