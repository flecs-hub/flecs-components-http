#include <include/http.h>

void EcsHttpInit(EcsRows *rows) {
    void *row;
    for (row = rows->first; row < rows->last; row = ecs_next(rows, row)) {
        EcsHandle entity = ecs_entity(row);
        ecs_add(rows->world, entity, EcsComponent_h);
        ecs_commit(rows->world, entity);
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

    /* This system adds the EcsComponent component to entities with the
     * EcsHttpServer component. This lets application use the server as a
     * component on endpoint entities, which determines which endpoints belong
     * to which server */
    ECS_SYSTEM(world, EcsHttpInit, EcsOnAdd, EcsHttpServer);

    handles->HttpServer = EcsHttpServer_h;
    handles->HttpEndpoint = EcsHttpEndpoint_h;
}
