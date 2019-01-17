#include <include/http.h>

void EcsHttpInit(EcsRows *rows) {
    void *row;
    for (row = rows->first; row < rows->last; row = ecs_next(rows, row)) {
        EcsEntity entity = ecs_entity(rows, row, 0);
        ecs_add(rows->world, entity, EcsContainer_h);
    }
}

void EcsComponentsHttp(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    EcsComponentsHttpHandles *handles = handles_out;
    ECS_COMPONENT(world, EcsHttpServer);
    ECS_COMPONENT(world, EcsHttpEndpoint);

    /* This system adds the EcsContainer component to entities with the
     * EcsHttpServer component. This lets application use the server as a
     * container for endpoints */
    ECS_SYSTEM(world, EcsHttpInit, EcsOnAdd, EcsHttpServer);

    handles->HttpServer = EcsHttpServer_h;
    handles->HttpEndpoint = EcsHttpEndpoint_h;
}
