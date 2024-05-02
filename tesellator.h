// Failed attempt at Ear Clipping algorithm

#ifndef TESSELLATOR_H
#define TESSELLATOR_H

#include <iostream>
#include <vector>
#include <cmath>

struct Vertex {
    float x, y, z;
    bool isConvex = false; // Flag to mark vertex as convex or concave
};

// Helper function to calculate the cross product of two vectors
float crossProduct(const Vertex& a, const Vertex& b, const Vertex& c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool isConvex(const Vertex& prev, const Vertex& curr, const Vertex& next) {
    float cross = crossProduct(prev, curr, next);
    return cross < 0; // Convex if cross product is negative
}

bool isEar(const Vertex& prev, const Vertex& curr, const Vertex& next, const std::vector<Vertex>& vertices) {
    if (!isConvex(prev, curr, next))
        return false;

    // Check if no other vertex is inside the triangle formed by prev, curr, next
    for (const Vertex& v : vertices) {
        if (&v != &prev && &v != &curr && &v != &next) {
            float area = std::abs(crossProduct(prev, curr, v)) +
                std::abs(crossProduct(curr, next, v)) +
                std::abs(crossProduct(next, prev, v));
            if (std::abs(area - std::abs(crossProduct(prev, curr, next))) < 1e-6f)
                return false; // Vertex is inside the triangle
        }
    }

    return true;
}

// Helper function to remove a vertex from the list
void removeVertex(std::vector<Vertex>& vertices, int index) {
    vertices.erase(vertices.begin() + index);
}

std::vector<Vertex> earClipping(const float* arr, int vertexCount) {
    std::vector<Vertex> vertices;
    for (int i = 0; i < vertexCount; ++i) {
        Vertex v;
        v.x = arr[i * 3];
        v.y = arr[i * 3 + 1];
        v.z = arr[i * 3 + 2];
        vertices.push_back(v);
    }

    std::vector<Vertex> triangles;

    while (vertices.size() >= 3) {
        bool earFound = false;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Vertex& prev = vertices[(i + vertices.size() - 1) % vertices.size()];
            const Vertex& curr = vertices[i];
            const Vertex& next = vertices[(i + 1) % vertices.size()];
            if (isEar(prev, curr, next, vertices)) {
                triangles.push_back(prev);
                triangles.push_back(curr);
                triangles.push_back(next);
                removeVertex(vertices, i);
                earFound = true;
                break;
            }
        }
        if (!earFound)
            break; // No more ears found, stop
    }

    return triangles;
}

#endif