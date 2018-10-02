// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _MICROXRCE_CLIENT_PROFILE_SESSION_CREATE_ENTITIES_XML_H_
#define _MICROXRCE_CLIENT_PROFILE_SESSION_CREATE_ENTITIES_XML_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <microxrce/client/profile/session/common_create_entities.h>

MRDLLAPI uint16_t uxr_write_configure_participant_xml(mrSession* session, mrStreamId stream_id,
                                         mrObjectId object_id, uint16_t domain, const char* xml, uint8_t mode);

MRDLLAPI uint16_t uxr_write_configure_topic_xml(mrSession* session, mrStreamId stream_id,
                                   mrObjectId object_id, mrObjectId participant_id, const char* xml, uint8_t mode);

MRDLLAPI uint16_t uxr_write_configure_publisher_xml(mrSession* session, mrStreamId stream_id,
                                       mrObjectId object_id, mrObjectId participant_id, const char* xml, uint8_t mode);

MRDLLAPI uint16_t uxr_write_configure_subscriber_xml(mrSession* session, mrStreamId stream_id,
                                        mrObjectId object_id, mrObjectId participant_id, const char* xml, uint8_t mode);

MRDLLAPI uint16_t uxr_write_configure_datawriter_xml(mrSession* session, mrStreamId stream_id,
                                        mrObjectId object_id, mrObjectId publisher_id, const char* xml, uint8_t mode);

MRDLLAPI uint16_t uxr_write_configure_datareader_xml(mrSession* session, mrStreamId stream_id,
                                        mrObjectId object_id, mrObjectId subscriber_id, const char* xml, uint8_t mode);

#ifdef __cplusplus
}
#endif

#endif //_MICROXRCE_CLIENT_PROFILE_SESSION_CREATE_ENTITIES_XML_H_