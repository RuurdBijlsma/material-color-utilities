from pathlib import Path

import pytest


@pytest.fixture(scope="module")
def assets_folder() -> Path:
    return Path(__file__).parent / "assets"
