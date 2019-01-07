#ifndef REFLECS_COMPONENTS_HTTP_H
#define REFLECS_COMPONENTS_HTTP_H

#include "bake_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum EcsHttpMethod {
    EcsHttpGet,
    EcsHttpPost,
    EcsHttpPut,
    EcsHttpDelete,
    EcsHttpMethodUnknown
} EcsHttpMethod;

typedef struct EcsHttpEndpoint EcsHttpEndpoint;

typedef struct EcsHttpRequest {
    const char *url;
    const char *relative_url;
    const char *params;
    void *ctx;
    EcsHttpMethod method;
    EcsHandle server;
} EcsHttpRequest;

typedef struct EcsHttpReply {
    char *header;
    char *body;
    int status;
    bool is_file;
} EcsHttpReply;

typedef bool (*EcsHttpServiceAction)(
    EcsWorld *world,
    EcsHandle entity,
    EcsHttpEndpoint *endpoint,
    EcsHttpRequest *request,
    EcsHttpReply *reply);

typedef struct EcsHttpServer {
    uint16_t port;
} EcsHttpServer;

struct EcsHttpEndpoint {
    char *url;
    void *ctx;
    bool synchronous;
    EcsHttpServiceAction action;
};

typedef struct EcsComponentsHttpHandles {
    EcsHandle HttpServer;
    EcsHandle HttpEndpoint;
} EcsComponentsHttpHandles;

void EcsComponentsHttp(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsHttp_DeclareHandles(handles)\
    EcsDeclareHandle(handles, HttpServer);\
    EcsDeclareHandle(handles, HttpEndpoint);

#ifdef __cplusplus
}
#endif

#endif
