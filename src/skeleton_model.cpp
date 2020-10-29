#define GLM_ENABLE_EXPERIMENTAL
// glm
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>

// project
#include "cgra/cgra_geometry.hpp"
#include "cgra/cgra_shader.hpp"
#include "cgra/cgra_mesh.hpp"
#include "skeleton_model.hpp"
#include "application.hpp"

#include <iostream>

using namespace std;
using namespace glm;
using namespace cgra;

void skeleton_model::draw(const mat4 &view, const mat4 &proj) {
    // set up the shader for every draw call
    glUseProgram(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader, "uProjectionMatrix"), 1, false, value_ptr(proj));

    // if the skeleton is not empty, then draw
    if (!skel.bones.empty()) {
        drawMesh(view, 0, proj);
    }
}

void basic_model2::drawJoint(const mat4 &view, const mat4 &proj) {
    mat4 modelTransformations(view);
    modelTransformations = glm::scale(modelTransformations, vec3(0.03));
    
    // set up the shader for every draw call
    glUseProgram(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader, "uProjectionMatrix"), 1, false, value_ptr(proj));
    glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewMatrix"), 1, false, value_ptr(modelTransformations));
    glUniform3fv(glGetUniformLocation(shader, "uColor"), 1, value_ptr(color));
    
    //mesh.draw();
    drawSphere();
}

void basic_model2::drawBone(const mat4 &view, const mat4 &proj, skeleton_bone currentBone) {
    mat4 modelTransformations(view);
    modelTransformations *= glm::orientation(currentBone.direction, vec3(0.0, 0.0, 1.0));
    modelTransformations = glm::scale(modelTransformations, vec3(0.01, 0.01, currentBone.length));
    
    // set up the shader for every draw call
    glUseProgram(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader, "uProjectionMatrix"), 1, false, value_ptr(proj));
    glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewMatrix"), 1, false, value_ptr(modelTransformations));
    glUniform3fv(glGetUniformLocation(shader, "uColor"), 1, value_ptr(color));
    
    //mesh.draw();
    cout<<"draw cyl"<<endl;
    drawCylinder();
}

void basic_model2::drawArrowX(const mat4 &view, const mat4 &proj, skeleton_bone currentBone) {
    mat4 modelTransformations(view);
    cout<<"bone basis "<<currentBone.basis.x<<endl;
    modelTransformations *= glm::rotate(glm::mat4(1), glm::pi<float>() / 2.0f, glm::vec3(0, 1, 0));
//modelTransformations = glm::rotate(modelTransformations, currentBone.basis.x,glm::vec3(0,1,0));
// modelTransformations = glm::rotate(modelTransformations, currentBone.basis.y,glm::vec3(0,1,0));
// modelTransformations = glm::rotate(modelTransformations, currentBone.basis.z,glm::vec3(0,1,0));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.y, glm::vec3(1));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.z, glm::vec3(1));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.x, glm::vec3(1));
    modelTransformations = glm::scale(modelTransformations, vec3(0.005, 0.005, 0.1));
    
    // set up the shader for every draw call
    glUseProgram(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader, "uProjectionMatrix"), 1, false, value_ptr(proj));
    glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewMatrix"), 1, false, value_ptr(modelTransformations));
    glUniform3fv(glGetUniformLocation(shader, "uColor"), 1, value_ptr(color));
    
    //mesh.draw();
    drawCylinder();
}
void basic_model2::drawArrowY(const mat4 &view, const mat4 &proj, skeleton_bone currentBone) {
    mat4 modelTransformations(view);
    //modelTransformations *= glm::orientation(currentBone.direction, currentBone.basis);
    modelTransformations *= glm::rotate(glm::mat4(1), glm::pi<float>() / 2.0f, glm::vec3(-1, 0, 0));
//    modelTransformations = glm::rotate(modelTransformations, currentBone.basis.x,glm::vec3(-1,0,0));
//    modelTransformations = glm::rotate(modelTransformations, currentBone.basis.y,glm::vec3(-1,0,0));
//    modelTransformations = glm::rotate(modelTransformations, currentBone.basis.z,glm::vec3(-1,0,0));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.y, glm::vec3(1));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.z, glm::vec3(1));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.x, glm::vec3(1));


    modelTransformations = glm::scale(modelTransformations, vec3(0.005, 0.005, 0.1));
    
    // set up the shader for every draw call
    glUseProgram(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader, "uProjectionMatrix"), 1, false, value_ptr(proj));
    glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewMatrix"), 1, false, value_ptr(modelTransformations));
    glUniform3fv(glGetUniformLocation(shader, "uColor"), 1, value_ptr(color));
    
    //mesh.draw();
    drawCylinder();
}
void basic_model2::drawArrowZ(const mat4 &view, const mat4 &proj, skeleton_bone currentBone) {
    mat4 modelTransformations(view);
    //modelTransformations *= glm::orientation(currentBone.direction, currentBone.basis);
    modelTransformations *= glm::rotate(glm::mat4(1), glm::pi<float>() / 2.0f, glm::vec3(0, 0, 1));
//    modelTransformations = glm::rotate(modelTransformations, currentBone.basis.x,glm::vec3(0,0,1));
//    modelTransformations = glm::rotate(modelTransformations, currentBone.basis.y,glm::vec3(0,0,1));
//    modelTransformations = glm::rotate(modelTransformations, currentBone.basis.z,glm::vec3(0,0,1));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.y, glm::vec3(1));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.z, glm::vec3(1));
    modelTransformations *= glm::rotate(glm::mat4(1), currentBone.basis.x, glm::vec3(1));
    modelTransformations = glm::scale(modelTransformations, vec3(0.005, 0.005, 0.1));
    
    // set up the shader for every draw call
    glUseProgram(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader, "uProjectionMatrix"), 1, false, value_ptr(proj));
    glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewMatrix"), 1, false, value_ptr(modelTransformations));
    glUniform3fv(glGetUniformLocation(shader, "uColor"), 1, value_ptr(color));
    
    //mesh.draw();
    drawCylinder();
}

void skeleton_model::drawMesh(const mat4 &parentTransform, int boneid, const mat4 &proj) {
    // TODO
    cout<<"bone id: "<<boneid<<endl;
    mat4 modelTrans(parentTransform);
    skeleton_bone currentBone;
        //find the current bone by checking id
        for(int i = 0; i<(int)skel.bones.size(); i++){
            if(skel.findBone(skel.bones[i].name) == boneid){
                currentBone = skel.bones[i];
            }
        }
    m_joint_mesh.drawJoint(parentTransform, proj);
    m_bone_mesh.drawBone(parentTransform, proj, currentBone);
    if(boneid != 0){
        m_arrowx_mesh.drawArrowX(parentTransform, proj, currentBone);
        m_arrowy_mesh.drawArrowY(parentTransform, proj, currentBone);
        m_arrowz_mesh.drawArrowZ(parentTransform, proj, currentBone);
    }
    
    //Offset transformation from the parent to child (direction*length) then rotation based on the axis
    modelTrans = glm::translate(modelTrans, currentBone.direction * currentBone.length);
    cout<<"children "<<currentBone.children.size()<<endl;
    //recursively do the same for the children
    for (int child : currentBone.children){
        int newID = skel.findBone(skel.bones[child].name);
        drawMesh(modelTrans, newID, proj);
    }
}

