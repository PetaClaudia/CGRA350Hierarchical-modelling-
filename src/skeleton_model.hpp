#pragma once

// glm
#include <glm/glm.hpp>

// project
#include "opengl.hpp"
#include "skeleton.hpp"
#include "cgra/cgra_mesh.hpp"

struct basic_model2 {
    GLuint shader = 0;
    cgra::gl_mesh mesh;
    glm::vec3 color{0.7};
    glm::mat4 modelTransform{1.0};
    GLuint texture;
    
    void drawJoint(const glm::mat4 &view, const glm::mat4 &proj);
    void drawBone(const glm::mat4 &view, const glm::mat4 &proj, skeleton_bone currentBone);
    void drawArrowX(const glm::mat4 &view, const glm::mat4 &proj, skeleton_bone currentBone);
    void drawArrowY(const glm::mat4 &view, const glm::mat4 &proj, skeleton_bone currentBone);
    void drawArrowZ(const glm::mat4 &view, const glm::mat4 &proj, skeleton_bone currentBone);
};

class skeleton_model {
private:
	// recursive helper method
	void drawMesh(const glm::mat4 &view, int boneid, const glm::mat4 &proj);
    
public:
	GLuint shader = 0;
	skeleton_data skel;
	skeleton_pose pose;
    
    basic_model2 m_joint_mesh;
    basic_model2 m_bone_mesh;
    basic_model2 m_arrowx_mesh;
    basic_model2 m_arrowy_mesh;
    basic_model2 m_arrowz_mesh;

	skeleton_model() { }
	void draw(const glm::mat4 &view, const glm::mat4 &proj);
};
