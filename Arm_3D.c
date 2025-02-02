#include "Arm_3D.h"

ARM arm1, arm2, arm3;

void InitArms() {
    // Initialisation des bras
    arm1 = (ARM){{0.0f, 0.0f, 0.0f}, {0.0f, 30.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 360.0f, 0.0f}, 2.5f, 9.0f, 20, BLUE};
    arm2 = (ARM){{0.0f, arm1.h, 0.0f}, {45.0f, 0.0f, 0.0f}, {-90.0f, 0.0f, 0.0f}, {90.0f, 0.0f, 0.0f}, 2.0f, 8.0f, 20, SKYBLUE};
    arm3 = (ARM){{0.0f, arm2.h, 0.0f}, {0.0f, 0.0f, 0.0f}, {-90.0f, 0.0f, 0.0f}, {90.0f, 0.0f, 0.0f}, 1.5f, 6.0f, 20, LIGHTGRAY};

    // Création des maillages et modèles
    Mesh mesh1 = GenMeshCylinder(arm1.rt, arm1.h, arm1.slice);
    arm1.model = LoadModelFromMesh(mesh1);

    Mesh mesh2 = GenMeshCylinder(arm2.rt, arm2.h, arm2.slice);
    arm2.model = LoadModelFromMesh(mesh2);

    Mesh mesh3 = GenMeshCylinder(arm3.rt, arm3.h, arm3.slice);
    arm3.model = LoadModelFromMesh(mesh3);
}

void UpdatePos() {
    // Transformation de arm1
    Matrix rotation1 = MatrixRotateXYZ((Vector3){arm1.rot.x * DEG2RAD, arm1.rot.y * DEG2RAD, arm1.rot.z * DEG2RAD});
    Matrix translation1 = MatrixTranslate(arm1.pos.x, arm1.pos.y, arm1.pos.z);
    arm1.model.transform = MatrixMultiply(translation1, rotation1);

    // Transformation de arm2 (attaché à arm1)
    Matrix translation2 = MatrixTranslate(0.0f, arm1.h, 0.0f); // Déplacement relatif
    Matrix rotation2 = MatrixRotateXYZ((Vector3){arm2.rot.x * DEG2RAD, arm2.rot.y * DEG2RAD, arm2.rot.z * DEG2RAD});
    arm2.model.transform = MatrixMultiply(MatrixMultiply(rotation2, translation2), arm1.model.transform);

    // Transformation de arm3 (attaché à arm2)
    Matrix translation3 = MatrixTranslate(0.0f, arm2.h, 0.0f);
    Matrix rotation3 = MatrixRotateXYZ((Vector3){arm3.rot.x * DEG2RAD, arm3.rot.y * DEG2RAD, arm3.rot.z * DEG2RAD});
    arm3.model.transform = MatrixMultiply(MatrixMultiply(rotation3, translation3), arm2.model.transform);
}

void DrawArm(ARM arm) {
    DrawModel(arm.model, (Vector3){0, 0, 0}, 1.0f, arm.color); // Utiliser DrawModel au lieu de DrawModelEx
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [3D] - Model-based Arm");
    InitArms();

    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 1.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Contrôles pour bouger arm1, arm2 et arm3
        if (IsKeyDown(KEY_ONE)) {
            if (arm1.rot_min.y < arm1.rot.y) arm1.rot.y -= 5.0f;
        }
        if (IsKeyDown(KEY_TWO)) {
            if (arm1.rot.y < arm1.rot_max.y) arm1.rot.y += 5.0f;
        }
        if (IsKeyDown(KEY_THREE)) {
            if (arm2.rot_min.x < arm2.rot.x) arm2.rot.x -= 5.0f;
        }
        if (IsKeyDown(KEY_FOUR)) {
            if (arm2.rot.x < arm2.rot_max.x) arm2.rot.x += 5.0f;
        }
        if (IsKeyDown(KEY_FIVE)) {
            if (arm3.rot_min.x < arm3.rot.x) arm3.rot.x -= 5.0f;
        }
        if (IsKeyDown(KEY_SIX)) {
            if (arm3.rot.x < arm3.rot_max.x) arm3.rot.x += 5.0f;
        }

        UpdateCamera(&camera, CAMERA_FREE);
        UpdatePos();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        DrawGrid(1000, 1.0f); 
        // Affichage des bras
        DrawArm(arm1);
        DrawArm(arm2);
        DrawArm(arm3);

        EndMode3D();
        DrawText("Use Mouse to move Camera", 10, 10, 20, BLACK);
        EndDrawing();
    }

    UnloadModel(arm1.model);
    UnloadModel(arm2.model);
    UnloadModel(arm3.model);
    CloseWindow();
    return 0;
}
