1. ray 代表相机光线
   1. origin 坐标
   2. direction 方向
2. hit 代表相机光线与物体的碰撞点
   1. t 代表距离
   2. material*
   3. normal 法向向量
3. light 代表光源
   1. DirectionalLight
      1. direction 光源
      2. color 颜色
   2. PointLight
      1. position 位置
      2. color 颜色
4. material
   1. diffuseColor 漫反射参数
   2. specularColor 镜面反射参数
   3. shininess 高光锐度