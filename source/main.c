#include "ddl.h"
#include "hc32f005.h"
#include "gpio.h"
// ===================== 核心配置 =====================
// 芯片引脚13 = P26 → 端口2，引脚6
#define LED_PORT    GpioPort2
#define LED_PIN     GpioPin6

// ===================== 主函数 =====================
int main(void)
{
    // 1. 系统初始化
    SystemInit();
    
    // 2. 开启GPIO时钟
    Sysctrl_SetPeripheralGate(SysctrlPeripheralGpio, TRUE);
    
    // 3. 配置P26为输出模式
    stc_gpio_cfg_t stcGpioCfg;
    DDL_ZERO_STRUCT(stcGpioCfg);
    stcGpioCfg.enDir = GpioDirOut;
    stcGpioCfg.enDrv = GpioDrvH;
    stcGpioCfg.enPu = GpioPuDisable;
    stcGpioCfg.enPd = GpioPdDisable;
    stcGpioCfg.enOD = GpioOdDisable;
    Gpio_Init(LED_PORT, LED_PIN, &stcGpioCfg);
    
    // 4. 默认熄灭LED
    Gpio_WriteOutputIO(LED_PORT, LED_PIN, TRUE);

    while(1)
    {
        Gpio_WriteOutputIO(LED_PORT, LED_PIN, FALSE);  // 点亮LED
        delay1ms(500);                                 // 500ms延时
        Gpio_WriteOutputIO(LED_PORT, LED_PIN, TRUE);   // 熄灭LED
        delay1ms(500);                                 // 500ms延时AA
    }
}
