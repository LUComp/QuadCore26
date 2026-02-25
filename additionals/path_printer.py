from dataclasses import dataclass
import math
import logging

log = logging.getLogger(__name__)


@dataclass
class Point:
    x: float
    y: float
    z: float

ORIGIN = Point(0, 0, 0)


def path_finder(*, start: Point = ORIGIN, end: Point, step_length: float):
    res = []

    delta_x, delta_y, delta_z = end.x - start.x, end.y - start.y, end.z - start.z

    displacement = math.sqrt(delta_x ** 2 + delta_y ** 2 + delta_z ** 2)

    if displacement == 0:
        return []

    num_steps = int(displacement // step_length)

    for i in range(1, num_steps + 1):
        ratio = step_length / displacement * i
        x_i = start.x + delta_x * ratio
        y_i = start.y + delta_y * ratio
        z_i = start.z + delta_z * ratio

        p = Point(round(x_i, 2), round(y_i, 2), round(z_i, 2))
        res.append(p)
        log.debug("Step %s: %s", i, p)

    return res


def main():
    log.info("Test 1")

    target1 = Point(10, 2, 3)
    coordinates1 = path_finder(end=target1, step_length=2.0)

    log.info("--------------------------------------------")

    log.info("Test 2")

    target2 = Point(-50, 75, -134)
    coordinates2 = path_finder(start=Point(31, -7, 11), end=target2, step_length=4.5)


if __name__ == "__main__":
    logging.basicConfig(level=logging.DEBUG)
    main()

