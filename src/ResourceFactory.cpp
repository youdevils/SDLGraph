#include "../include/ResourceFactory.hpp"

ResourceFactory::ResourceFactory()
{
}

ResourceFactory::~ResourceFactory()
{
}
ResourceFactory &ResourceFactory::GetInstance()
{
    static ResourceFactory *s_instance = new ResourceFactory;
    return *s_instance;
}

std::shared_ptr<Menu> ResourceFactory::CreateMenu(int xx, int yy, int ww, int hh, std::shared_ptr<Font> font)
{
    if (m_menu == nullptr)
    {
        m_menu = std::make_shared<Menu>(xx, yy, ww, hh, font);
    }
    return m_menu;
}

std::shared_ptr<Menu> ResourceFactory::GetMenu()
{
    return m_menu;
}

std::shared_ptr<Font> ResourceFactory::CreateFont(const char *name, const char *path, int size)
{
    auto search = m_fonts.find(name);
    if (search != m_fonts.end())
    {
        return m_fonts[name];
    }
    else
    {
        std::shared_ptr<Font> font = std::make_shared<Font>(SDLResourceManager::GetInstance().GetTTF(path, size));
        m_fonts.insert({name, font});
        return m_fonts[name];
    }
    return nullptr;
}

std::shared_ptr<Font> ResourceFactory::GetFont(const char *name)
{
    auto search = m_fonts.find(name);
    if (search != m_fonts.end())
    {
        return m_fonts[name];
    }
    else
    {
        return nullptr;
    }
}

void ResourceFactory::AddPoint(const char *name, const float x, const float y)
{
    std::shared_ptr<Point> point = std::make_shared<Point>(Point(name, x, y));
    m_points.push_back(point);
}

std::vector<std::shared_ptr<Point>> &ResourceFactory::GetPoints()
{
    return m_points;
}

void ResourceFactory::ClearPoints()
{
    m_points.clear();
}
