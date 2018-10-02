#include <microxrce/client/core/session/stream_id.h>
#include <microxrce/client/core/serialization/xrce_header.h>

#define BEST_EFFORT_STREAM_THRESHOLD 1
#define RELIABLE_STREAM_THRESHOLD  128

//==================================================================
//                             PUBLIC
//==================================================================
uxrStreamId uxr_stream_id(uint8_t index, uxrStreamType type, uxrStreamDirection direction)
{
    uxrStreamId stream_id;
    stream_id.direction = direction;
    stream_id.index = index;
    stream_id.type = type;

    switch(type)
    {
        case UXR_NONE_STREAM:
            stream_id.raw = index;
            break;
        case UXR_BEST_EFFORT_STREAM:
            stream_id.raw = (uint8_t)(index + BEST_EFFORT_STREAM_THRESHOLD);
            break;
        case UXR_RELIABLE_STREAM:
            stream_id.raw = (uint8_t)(index + RELIABLE_STREAM_THRESHOLD);
            break;
    }

    return stream_id;
}

uxrStreamId uxr_stream_id_from_raw(uint8_t stream_id_raw, uxrStreamDirection direction)
{
    uxrStreamId stream_id;
    stream_id.raw = stream_id_raw;
    stream_id.direction = direction;

    if(BEST_EFFORT_STREAM_THRESHOLD > stream_id_raw)
    {
        stream_id.index = stream_id_raw;
        stream_id.type = UXR_NONE_STREAM;
    }
    else if(RELIABLE_STREAM_THRESHOLD > stream_id_raw)
    {
        stream_id.index = (uint8_t)(stream_id_raw - BEST_EFFORT_STREAM_THRESHOLD);
        stream_id.type = UXR_BEST_EFFORT_STREAM;
    }
    else
    {
        stream_id.index = (uint8_t)(stream_id_raw - RELIABLE_STREAM_THRESHOLD);
        stream_id.type = UXR_RELIABLE_STREAM;
    }

    return stream_id;
}
