#ifndef GUI_CONTAINER_H
#define GUI_CONTAINER_H
#include "../Renderer/Renderer.h"
#include "../Renderer/TextRenderer.h"
#include "../Renderer/shader.h"
#include "../Scene/Camera.h"
#include "GUIElement.h"
#include "GUIButton.h"

#include <vector>

class GUIContainer
{
private:
    std::vector<std::shared_ptr<GUIElement>> m_Elements;
protected:
    void AddElement(std::shared_ptr<GUIElement> element);
    void RemoveElement(std::shared_ptr<GUIElement> element);
    bool m_IsActive;

    glm::vec2 m_Position;
    glm::vec2 m_Scale;
public:
    GUIContainer();

    bool IsActive();
    glm::vec2 GetPosition();
    glm::vec2 GetScale();

    void SetActive(bool active);
    void SetPosition(glm::vec2 position);
    void SetScale(glm::vec2 scale);

    virtual bool Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(Renderer *renderer, TextRenderer *textRenderer, std::shared_ptr<Camera> camera);
    // template method pattern: allow GUI systems to override RenderBackground
    virtual void RenderBackground(Renderer *renderer, TextRenderer *textRenderer);

    virtual void OnActivate();
    virtual void OnDeactivate();

    void OnKeyPressed(char key);
    void OnKeyReleased(char key);
    void OnMouseMove(float x, float y);
    void OnMouseClick(bool leftButton);

    virtual void ButtonPressed(std::shared_ptr<GUIButton> pButton);
};
#endif