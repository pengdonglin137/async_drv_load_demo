#include <linux/module.h>
#include <linux/of.h>
#include <linux/delay.h>
#include <linux/i2c.h>

#define USE_ASYNC

static int async_demo5_probe(struct i2c_client *i2c,
			 const struct i2c_device_id *id)
{
	printk("%s enter\n", __func__);
	msleep(100);
	printk("%s exit\n", __func__);
	return 0;
}

static int async_demo5_remove(struct i2c_client *i2c)
{
	printk("%s enter\n", __func__);
	return 0;
}

static const struct i2c_device_id async_demo5_i2c_id[] = {
	{ "async_demo5_i2c", },
	{ }
};
MODULE_DEVICE_TABLE(i2c, async_demo5_i2c_id);

static const struct of_device_id async_demo5_i2c_dt_ids[] = {
	{ .compatible = "async_demo5_i2c", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo5_i2c_dt_ids);

static struct i2c_driver async_demo5_i2c_driver = {
	.probe	        = async_demo5_probe,
	.remove         = async_demo5_remove,
	.id_table       = async_demo5_i2c_id,
	.driver         = {
		.name           = "async_demo5_i2c",
		.of_match_table = async_demo5_i2c_dt_ids,
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static int async_demo4_probe(struct i2c_client *i2c,
			 const struct i2c_device_id *id)
{
	printk("%s enter\n", __func__);
	msleep(1000);
	printk("%s exit\n", __func__);
	return 0;
}

static int async_demo4_remove(struct i2c_client *i2c)
{
	printk("%s enter\n", __func__);
	return 0;
}

static const struct i2c_device_id async_demo4_i2c_id[] = {
	{ "async_demo4_i2c", },
	{ }
};
MODULE_DEVICE_TABLE(i2c, async_demo4_i2c_id);

static const struct of_device_id async_demo4_i2c_dt_ids[] = {
	{ .compatible = "async_demo4_i2c", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo4_i2c_dt_ids);

static struct i2c_driver async_demo4_i2c_driver = {
	.probe	        = async_demo4_probe,
	.remove         = async_demo4_remove,
	.id_table       = async_demo4_i2c_id,
	.driver         = {
		.name           = "async_demo4_i2c",
		.of_match_table = async_demo4_i2c_dt_ids,
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static int async_demo3_probe(struct i2c_client *i2c,
			 const struct i2c_device_id *id)
{
	printk("%s enter\n", __func__);
	msleep(2000);
	printk("%s exit\n", __func__);
	return 0;
}

static int async_demo3_remove(struct i2c_client *i2c)
{
	printk("%s enter\n", __func__);
	return 0;
}

static const struct i2c_device_id async_demo3_i2c_id[] = {
	{ "async_demo3_i2c", },
	{ }
};
MODULE_DEVICE_TABLE(i2c, async_demo3_i2c_id);

static const struct of_device_id async_demo3_i2c_dt_ids[] = {
	{ .compatible = "async_demo3_i2c", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo3_i2c_dt_ids);

static struct i2c_driver async_demo3_i2c_driver = {
	.probe	        = async_demo3_probe,
	.remove         = async_demo3_remove,
	.id_table       = async_demo3_i2c_id,
	.driver         = {
		.name           = "async_demo3_i2c",
		.of_match_table = async_demo3_i2c_dt_ids,
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static int async_demo2_probe(struct i2c_client *i2c,
			 const struct i2c_device_id *id)
{
	printk("%s enter\n", __func__);
	msleep(3000);
	printk("%s exit\n", __func__);
	return 0;
}

static int async_demo2_remove(struct i2c_client *i2c)
{
	printk("%s enter\n", __func__);
	return 0;
}

static const struct i2c_device_id async_demo2_i2c_id[] = {
	{ "async_demo2_i2c", },
	{ }
};
MODULE_DEVICE_TABLE(i2c, async_demo2_i2c_id);

static const struct of_device_id async_demo2_i2c_dt_ids[] = {
	{ .compatible = "async_demo2_i2c", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo2_i2c_dt_ids);

static struct i2c_driver async_demo2_i2c_driver = {
	.probe	        = async_demo2_probe,
	.remove         = async_demo2_remove,
	.id_table       = async_demo2_i2c_id,
	.driver         = {
		.name           = "async_demo2_i2c",
		.of_match_table = async_demo2_i2c_dt_ids,
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static int async_demo1_probe(struct i2c_client *i2c,
			 const struct i2c_device_id *id)
{
	printk("%s enter\n", __func__);
	msleep(4000);
	printk("%s exit\n", __func__);
	return 0;
}

static int async_demo1_remove(struct i2c_client *i2c)
{
	printk("%s enter\n", __func__);
	return 0;
}

static const struct i2c_device_id async_demo1_i2c_id[] = {
	{ "async_demo1_i2c", },
	{ }
};
MODULE_DEVICE_TABLE(i2c, async_demo1_i2c_id);

static const struct of_device_id async_demo1_i2c_dt_ids[] = {
	{ .compatible = "async_demo1_i2c", },
	{  }
};
MODULE_DEVICE_TABLE(of, async_demo1_i2c_dt_ids);

static struct i2c_driver async_demo1_i2c_driver = {
	.probe	        = async_demo1_probe,
	.remove         = async_demo1_remove,
	.id_table       = async_demo1_i2c_id,
	.driver         = {
		.name           = "async_demo1_i2c",
		.of_match_table = async_demo1_i2c_dt_ids,
#ifdef USE_ASYNC
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
#else
		.probe_type = PROBE_FORCE_SYNCHRONOUS,
#endif
	},
};

static __init int async_demo_i2c_init(void)
{
	printk("%s enter.\n", __func__);

	printk("before async_demo1_i2c\n");
	i2c_add_driver(&async_demo1_i2c_driver);
	printk("before async_demo2_i2c\n");
	i2c_add_driver(&async_demo2_i2c_driver);
	printk("before async_demo3_i2c\n");
	i2c_add_driver(&async_demo3_i2c_driver);
	printk("before async_demo4_i2c\n");
	i2c_add_driver(&async_demo4_i2c_driver);
	printk("before async_demo5_i2c\n");
	i2c_add_driver(&async_demo5_i2c_driver);

	return 0;
}

static __exit void async_demo_i2c_exit(void)
{
	printk("%s enter.\n", __func__);

	i2c_del_driver(&async_demo1_i2c_driver);
	i2c_del_driver(&async_demo2_i2c_driver);
	i2c_del_driver(&async_demo3_i2c_driver);
	i2c_del_driver(&async_demo4_i2c_driver);
	i2c_del_driver(&async_demo5_i2c_driver);
}

module_init(async_demo_i2c_init);
module_exit(async_demo_i2c_exit);

MODULE_LICENSE("GPL");
