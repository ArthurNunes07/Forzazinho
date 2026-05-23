#ifndef TRACK_HPP
#define TRACK_HPP

#include "raylib.h"

/**
 * @brief Classe responsável pela pista do jogo.
 * 
 * Controla posição, dimensões e desenho da pista.
 */
class Pista{
  private:

    /// Posição horizontal da pista
    int x;

    /// Posição vertical da pista
    int y;

    /// Largura da pista
    int width;

    /// Altura da pista
    int height;

  public:

    /**
     * @brief Constrói a pista padrão do jogo.
     */
    Pista();

    /**
     * @brief Retorna a posição X da pista.
     * 
     * @return int posição horizontal
     */
    int GetX() const;

    /**
     * @brief Retorna a posição Y da pista.
     * 
     * @return int posição vertical
     */
    int GetY() const;

    /**
     * @brief Retorna a largura da pista.
     * 
     * @return int largura da pista
     */
    int GetWidth() const;

    /**
     * @brief Retorna a altura da pista.
     * 
     * @return int altura da pista
     */
    int GetHeight() const;

    /**
     * @brief Desenha a pista na tela.
     */
    void Draw();

};

#endif