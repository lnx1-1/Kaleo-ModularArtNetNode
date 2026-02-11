Import("env")
import subprocess


def _read_fw_version():
    try:
        version = subprocess.check_output(
            ["git", "describe", "--tags", "--always", "--dirty"],
            text=True,
            stderr=subprocess.DEVNULL,
        ).strip()
        if version:
            return version
    except Exception:
        pass
    return "unknown"


env.Append(
    CPPDEFINES=[
        ("SYNAPSE_FW_VERSION", '\\"%s\\"' % _read_fw_version()),
    ]
)

# Keep default builds quiet without affecting the strict env.
if env.get("PIOENV") == "wt32-eth01":
    # Suppress C-only warning from esp_dmx.
    env.Append(CFLAGS=["-Wno-discarded-qualifiers"])
    # Suppress C++17 register warnings from ArduinoLog.
    env.Append(CXXFLAGS=["-Wno-register"])
