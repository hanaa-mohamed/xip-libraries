// FIXME: add header, add __int64 support to SoInput and SoOutput

#include <Inventor/fields/SoMFInt64.h>
#include <stdlib.h>

#include <xip/system/standard.h>

//////////////////////////////////////////////////////////////////////////////
//
// SoMFInt64 class
//
//////////////////////////////////////////////////////////////////////////////

// Use standard definitions of all basic methods
SO_MFIELD_SOURCE_MALLOC(SoMFInt64, int64_t, int64_t);


//////////////////////////////////////////////////////////////////////////////
void	SoMFInt64::initClass()
{
	SO__FIELD_INIT_CLASS(SoMFInt64, "MFInt64", SoMField);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Reads one (indexed) value from file. Returns FALSE on error.
//
// Use: private

SbBool
SoMFInt64::read1Value(SoInput *in, int index)
//
////////////////////////////////////////////////////////////////////////
{
    //return in->read(values[index]);
    SbString input;
    SbBool res = in->read(input);
    values[index] = _strtoi64(input.getString(), NULL, 10);
    return res;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Writes one (indexed) value to file.
//
// Use: private

void
SoMFInt64::write1Value(SoOutput *out, int index) const
//
////////////////////////////////////////////////////////////////////////
{
    //out->write(values[index]);
    char buffer[65];
    _i64toa(values[index], buffer, 10); 
    out->write(buffer);
    out->write(' ');
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Returns number of ASCII values to write per output line.
//
// Use: private

int
SoMFInt64::getNumValuesPerLine() const
//
////////////////////////////////////////////////////////////////////////
{
    return 4;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Writes array of binary values to file as one chunk.
//
// Use: private

void
SoMFInt64::writeBinaryValues(SoOutput *out) const

//
////////////////////////////////////////////////////////////////////////
{
    //out->writeBinaryArray(values, num);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Reads array of binary values from file as one chunk.
//
// Use: private

SbBool
SoMFInt64::readBinaryValues(SoInput *in, int numToRead)
//
////////////////////////////////////////////////////////////////////////
{
    //return (in->readBinaryArray(values, numToRead));
    return FALSE;
}
