#pragma once
#include "buffer.h"
#include "indexbuff.h"
#include "vertexarray.h"
#include "renderer2d.h"
#include "shader.h"
#include "maths.h"
#include "texture.h"

namespace Phoenix
{
	namespace Graphics
	{
		struct VertexData
		{
			Maths::vec3 vertex;
			Maths::vec2 uv;	// For Texture Coordinates
			float texID;
			unsigned int color;

		};


		class Renderable2D
		{
		protected:
			Maths::vec3 m_Position;
			Maths::vec2 m_Size;
			Maths::vec3 m_Rotation;
			Maths::vec3 m_Scale;
			unsigned int m_Color;
			std::vector<Maths::vec2> m_UV;
			Texture* m_Texture;
		protected:
			Renderable2D() : m_Texture(nullptr) { setDefaultUV(); }

		public:
			Renderable2D(Maths::vec3 position, Maths::vec2 size, unsigned int color)
				:m_Position(position), m_Size(size), m_Color(color), m_Texture(nullptr)
			{setDefaultUV();}

			virtual ~Renderable2D() {}

			virtual void submit(Renderer2D* renderer) const
			{
				renderer->submit(this);
			}

			void setColor(unsigned int color) { m_Color = color; }
			void setColor(Maths::vec4 color)
			{
				int r = color.x * 255.0f;
				int g = color.y * 255.0f;
				int b = color.z * 255.0f;
				int a = color.w * 255.0f;
				m_Color = a << 24 | b << 16 | g << 8 | r;
			}

			 Maths::mat4 getTransform() const
			{
				Maths::mat4 positionMatrix = Maths::mat4::translation(m_Position);
				Maths::mat4 rotationMatrixX = Maths::mat4::rotate(m_Rotation.x, Maths::vec3(1, 0, 0));
				Maths::mat4 rotationMatrixY = Maths::mat4::rotate(m_Rotation.y, Maths::vec3(0, 1, 0));
				Maths::mat4 rotationMatrixZ = Maths::mat4::rotate(m_Rotation.z, Maths::vec3(0, 0, 1));
				Maths::mat4 scaleMatrix = Maths::mat4::scale(m_Scale);
			
				Maths::mat4 rotationMatrix = rotationMatrixZ * rotationMatrixY * rotationMatrixX;
				return positionMatrix * rotationMatrix * scaleMatrix;
			}

			Maths::vec3&  getRotation() { return m_Rotation; }
			Maths::vec3&  getScale() { return m_Scale; }
			void  setPosition(Maths::vec3& pos) { m_Position = pos; }
			void  setRotation(Maths::vec3& rot) { m_Rotation = rot; }
			void  setScale(Maths::vec3& scale) { m_Scale = scale; }
			void setPosititon(Maths::vec3 pos)
			{
				m_Position = pos;
			}
			void setSize(float x, float y) { m_Size.x = x; m_Size.y = y; }
			void setVelocity(Maths::vec3 newpos)
			{
				m_Position = m_Position + newpos;
			}
			void setGravity(float gravity) {
				m_Position = m_Position - Maths::vec3(0.0f, gravity, 0.0f);
			}
			Maths::vec3 getVelocity(float speed)
			{
				float length = sqrt((m_Position.x * m_Position.x) + (m_Position.y * m_Position.y) + (m_Position.z * m_Position.z));
				Maths::vec3 unitVelocity = Maths::vec3(m_Position.x / length, m_Position.y / length, m_Position.z / length);
				return Maths::vec3(unitVelocity.x * speed, unitVelocity.y * speed, unitVelocity.z*speed);
			}


			bool isColliding(Maths::vec3 pos, Maths::vec2 size)
			{
				float xmin = m_Position.x;
				float xmax = m_Position.x + m_Size.x;
				float ymax = m_Position.y + m_Size.y;
				float ymin = m_Position.y;

				float xtmin = pos.x;
				float xtmax = pos.x + size.x;
				float ytmax = pos.y + size.y;
				float ytmin = pos.y;
				
				//Collision test

				if (xmax < xtmin || xmin > xtmax) return false;
				if (ymax < ytmin || ymin > ytmax) return false;

				return true;
				
			}


			inline const Maths::vec3& getPosition() const { return m_Position; }
			inline const Maths::vec2& getSize() const { return m_Size; }
			inline const unsigned int getColor() const { return m_Color; }
			inline const std::vector<Maths::vec2>& getUV() const { return m_UV; }
			inline const GLint getTID() const { return m_Texture ? m_Texture->getID() : 0; }
		private:

			void setDefaultUV()
			{
				m_UV.push_back(Maths::vec2(0, 0));
				m_UV.push_back(Maths::vec2(0, 1));
				m_UV.push_back(Maths::vec2(1, 1));
				m_UV.push_back(Maths::vec2(1, 0));
			}

		};
	}
}
