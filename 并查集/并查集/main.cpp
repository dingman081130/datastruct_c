#include"structDef.h"

void main()
{
	UFSTree t[MaxSize];
	::MakeSet( t, MaxSize );
	::Union( t, 1, 3 );
	::Union( t, 3, 5 );
	::FindSet( t, 5 );

}