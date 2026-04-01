```markdown
# GraphoDro4

Консольное приложение для работы с графами на C++.

## Возможности

- Генерация графов 14 типов: полный, двудольный, дерево, звезда, цикл, путь, колесо, случайный, кубический, с заданным числом компонент связности, мостов, точек сочленения, 2-мостов, Халина.
- Загрузка из файлов в форматах: список рёбер, матрица смежности, DIMACS, SNAP.
- Вычисление метрик: плотность, диаметр, транзитивность, компоненты связности, точки сочленения, мосты, двудольность, верхняя оценка хроматического числа.
- Сохранение в форматах: GraphViz (.dot) и .edges (для programforyou.ru).

## Сборка

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Использование

Запустите исполняемый файл `GraphoDro4` (или `GraphoDro4.exe` на Windows).  
В интерактивной консоли доступны команды:

- **generate <тип> [параметры]** – сгенерировать граф
- **load <файл> <формат>** – загрузить граф
- **save <файл> <формат>** – сохранить граф
- **metric <имя>** – вычислить метрику
- **help** – справка
- **quit** – выход

### Типы генерации

| Тип | Параметры | Пример |
|-----|-----------|--------|
| complete | n | `generate complete 5` |
| complete_bipartite | n m | `generate complete_bipartite 3 4` |
| tree | n | `generate tree 10` |
| star | n | `generate star 8` |
| cycle | n | `generate cycle 6` |
| path | n | `generate path 7` |
| wheel | n | `generate wheel 6` |
| random | n p% | `generate random 20 30` |
| cubic | n (чётное ≥4) | `generate cubic 6` |
| components | n comp | `generate components 10 2` |
| bridges | n bridges | `generate bridges 10 3` |
| articulation | n ap | `generate articulation 10 2` |
| two_bridges | n twoBridges | `generate two_bridges 12 2` |
| halin | n | `generate halin 4` |

### Форматы загрузки

- `edgelist` – список рёбер (каждая строка `u v`)
- `adjmatrix` – матрица смежности (целые числа через пробел)
- `dimacs` – формат DIMACS (файлы раскраски)
- `snap` – формат SNAP (два числа на строку)

### Форматы сохранения

- `dot` – для Graphviz (визуализация)
- `edges` – для programforyou.ru (нумерация с 1)

### Доступные метрики

- `density` – плотность
- `diameter` – диаметр
- `transitivity` – транзитивность (отношение треугольников к триадам)
- `components` – количество компонент связности
- `articulation` – количество точек сочленения
- `bridges` – количество мостов
- `bipartite` – проверка на двудольность
- `chromatic` – верхняя оценка хроматического числа (жадная раскраска)

## Примеры

1. **Создать полный граф K5 и вычислить плотность:**
   ```
   > generate complete 5
   > metric density
   ```

2. **Сохранить граф в формате dot и открыть в GraphvizOnline:**
   ```
   > save graph.dot dot
   ```
   Загрузить файл на https://dreampuf.github.io/GraphvizOnline/

3. **Сохранить граф для programforyou.ru:**
   ```
   > save graph.edges edges
   ```

## Тестирование

После сборки выполните:
```bash
./tests        # Linux/macOS
tests.exe      # Windows
```

## Автор

Kango911
```