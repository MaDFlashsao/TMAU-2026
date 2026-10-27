# Лабораторная работа №1

## UML-диаграмма классов
```mermaid
classDiagram
    class Model {
        <<abstract>>
        +step(u) double
        +reset() void
    }
    class Model1_7 {
        -a, b1, b2, b3
        -y, u1, u2
        +step(u) double
    }
    class Model2_1 {
        -a, b, c, d
        -y, y_prev, u_prev
        +step(u) double
    }
    class Model3_5 {
        -b, dt
        -y
        +step(u) double
    }
    Model <|-- Model1_7
    Model <|-- Model2_1
    Model <|-- Model3_5