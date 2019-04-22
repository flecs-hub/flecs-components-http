#include <include/http.h>

void EcsHttpInit(ecs_rows_t *rows) {
    ecs_entity_t *e = ecs_column(rows, ecs_entity_t, 0);

    int i;
    for (i = 0; i < rows->count; i ++) {
        ecs_add(rows->world, e[i], EcsContainer);
    }
}

void FlecsComponentsHttpImport(
    ecs_world_t *world,
    int flags)
{
    ECS_MODULE(world, FlecsComponentsHttp);

    ECS_COMPONENT(world, EcsHttpServer);
    ECS_COMPONENT(world, EcsHttpEndpoint);

    /* This system adds the EcsContainer component to entities with the
     * EcsHttpServer component. This lets application use the server as a
     * container for endpoints */
    ECS_SYSTEM(world, EcsHttpInit, EcsOnAdd, EcsHttpServer);

    ECS_SET_COMPONENT(handles, EcsHttpServer);
    ECS_SET_COMPONENT(handles, EcsHttpEndpoint);
}
