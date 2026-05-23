#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "track.hpp"

/**
 * @brief Classe responsável pelo carro do jogador.
 * 
 * Controla movimentação, entrada do teclado,
 * colisão com a pista e desenho na tela.
 */
class Car{
  private:

    /// Posição horizontal do carro
    float x;

    /// Posição vertical do carro
    float y;

    /// Velocidade atual do carro
    float speed;

    /// Velocidade máxima permitida
    float max_speed;

    /// Ângulo de rotação do carro
    float angle;

    /// Altura do carro
    float height;

    /// Largura do carro
    float width;

    /// Indica se o carro está fora da pista
    bool offroad;

  public:

    /**
     * @brief Constrói um carro.
     * 
     * @param startX posição inicial no eixo X
     * @param startY posição inicial no eixo Y
     */
    Car(float startX, float startY);

    /**
     * @brief Desenha o carro na tela.
     */
    void DrawPlayer();

    /**
     * @brief Processa a entrada do jogador.
     * 
     * Controla aceleração, frenagem e rotação.
     * 
     * @param dt Delta time do frame
     */
    void PlayerInput(float dt);

    /**
     * @brief Move o carro baseado na velocidade e direção.
     * 
     * @param dt Delta time do frame
     */
    void MovePlayer(float dt);

    /**
     * @brief Atualiza o estado completo do carro.
     * 
     * @param dt Delta time do frame
     * @param p Referência para a pista atual
     */
    void Update(float dt, const Pista &p);

    /**
     * @brief Mantém o carro dentro dos limites da tela.
     */
    void KeepThisInsideScreen();

    /**
     * @brief Verifica colisão entre o carro e a pista.
     * 
     * @param p Referência para a pista atual
     */
    void CheckCollision(const Pista &p);

    /**
     * @brief Retorna a posição X do carro.
     * 
     * @return float posição horizontal
     */
    float GetX();

    /**
     * @brief Retorna a posição Y do carro.
     * 
     * @return float posição vertical
     */
    float GetY();

    /**
     * @brief Define a posição X do carro.
     * 
     * @param newX nova posição horizontal
     */
    void SetX(float newX);

    /**
     * @brief Define a posição Y do carro.
     * 
     * @param newY nova posição vertical
     */
    void SetY(float newY);

    /**
     * @brief Retorna a altura do carro.
     * 
     * @return float altura
     */
    float GetHeight();

    /**
     * @brief Retorna a largura do carro.
     * 
     * @return float largura
     */
    float GetWidth();

};

#endif