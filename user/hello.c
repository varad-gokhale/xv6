#include "types.h"
#include "stat.h"
#include "user.h"
#include "stat.h"

int main(int argc, char** argv)
{
	int a;

	a = getreadcount();
	printf(1, "getreadcount(): %d\n",a);
	
	exit();
}
