#ifndef FLECS_COMPONENTS_HTTP_H
#define FLECS_COMPONENTS_HTTP_H

#include <flecs-components-http/bake_config.h>

struct EcsHttpEndpoint;
struct EcsHttpRequest;
struct EcsHttpReply;

typedef bool (*EcsHttpServiceAction)(
    ecs_world_t *world,
    ecs_entity_t entity,
    struct EcsHttpEndpoint *endpoint,
    struct EcsHttpRequest *request,
    struct EcsHttpReply *reply);

#ifndef FLECS_LEGACY

ECS_ENUM(EcsHttpMethod, {
    EcsHttpGet,
    EcsHttpPost,
    EcsHttpPut,
    EcsHttpDelete,
    EcsHttpMethodUnknown
})

ECS_STRUCT(EcsHttpRequest, {
    const char *url;
    const char *relative_url;
    const char *params;
    void *ctx;
    EcsHttpMethod method;
    ecs_entity_t server;
})

ECS_STRUCT(EcsHttpReply, {
    char *header;
    char *body;
    int status;
    bool is_file;
})


ECS_STRUCT(EcsHttpServer, {
    uint16_t port;
})

ECS_STRUCT(EcsHttpEndpoint, {
    const char *url;
    void *ctx;
    bool synchronous;

ECS_PRIVATE
    EcsHttpServiceAction action;
})

#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef struct FlecsComponentsHttp {
    ECS_DECLARE_COMPONENT(EcsHttpServer);
    ECS_DECLARE_COMPONENT(EcsHttpEndpoint);
} FlecsComponentsHttp;

FLECS_COMPONENTS_HTTP_API 
void FlecsComponentsHttpImport(
    ecs_world_t *world);

/* Utility to get parameter from query string */
FLECS_COMPONENTS_HTTP_API
size_t ecs_http_get_query_param(
    const char *query,
    const char *name, 
    char *buffer, 
    size_t len);

#define FlecsComponentsHttpImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsHttpServer);\
    ECS_IMPORT_COMPONENT(handles, EcsHttpEndpoint);

#ifdef __cplusplus
}
#endif

#endif
