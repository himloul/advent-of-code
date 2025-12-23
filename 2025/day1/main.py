from pathlib import Path


def read_input() -> list[str]:
    return (Path(__file__).parent / "input.txt").read_text().splitlines()


def dial(point: int, rotation: str) -> int:
    sign = 1 if rotation[0] == "R" else -1
    return (point + (sign * int(rotation[1:]))) % 100


def part1(data: list[str]) -> int:
    count = 0
    position = 50
    for line in data:
        res = dial(position, line)
        if res == 0:
            count += 1
        position = res
    return count


def main():
    data = read_input()
    print("Part 1:", part1(data))


if __name__ == "__main__":
    main()
